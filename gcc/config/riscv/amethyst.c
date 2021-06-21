/* Amethyst specific routines for RISC-V.
   Copyright (C) 2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#define IN_TARGET_CODE 1

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "insn-attr-common.h"

/* Return the number of instructions needed to implement INSN,
   given that it loads from or stores to MEM. */

static int
riscv_amethyst_regfile_halves_rtx (rtx x)
{
  int i, r;
  rtx dest;

  switch (GET_CODE (x)) {
  case PARALLEL:
    r = 0;
    for (i = 0; i < XVECLEN (x, 0); ++i)
      r |= riscv_amethyst_regfile_halves_rtx (XVECEXP (x, 0, i));
    return r;

  case SET:
  case CLOBBER:
    dest = SET_DEST (x);
    if (REG_P (dest)) {
      if (!GP_REG_P (REGNO (dest)))
	return 0;
      if (GET_MODE (dest) == DImode)
	return 3;
      return 1 << (((int) (REGNO (dest)) - GP_REG_FIRST) & 1);
    }
    return 0;

  default:
    return 0;
  }
}

enum attr_rfwriteports
riscv_amethyst_regfile_halves (rtx_insn *insn)
{
  switch (riscv_amethyst_regfile_halves_rtx (PATTERN(insn))) {
  case 0:
    return RFWRITEPORTS_NONE;
  case 1:
    return RFWRITEPORTS_EVEN;
  case 2:
    return RFWRITEPORTS_ODD;
  default:
    return RFWRITEPORTS_BOTH;
  }
}

const char *
riscv_amethyst_output_veccmp (rtx op)
{
}

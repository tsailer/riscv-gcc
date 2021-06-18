;; Amethyst SIMD Instructions.
;; Copyright (C) 2021 Free Software Foundation, Inc.
;; Contributed by Thomas Sailer (t.sailer@alumni.ethz.ch).

;; This file is part of GCC.

;; GCC is free software; you can redistribute it and/or modify it
;; under the terms of the GNU General Public License as published
;; by the Free Software Foundation; either version 3, or (at your
;; option) any later version.

;; GCC is distributed in the hope that it will be useful, but WITHOUT
;; ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
;; or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
;; License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.


(define_insn "addv4qi3"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
    (plus:V4QI 
      (match_operand:V4QI 1 "register_operand" "r")
      (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwadd.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "usaddv4qi3"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
    (us_plus:V4QI 
      (match_operand:V4QI 1 "register_operand" "r")
      (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwaddus.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "ssaddv4qi3"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
    (ss_plus:V4QI 
      (match_operand:V4QI 1 "register_operand" "r")
      (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwaddss.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwavgu_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
    (truncate:V4QI (lshiftrt:V4HI (plus:V4HI 
      (zero_extend:V4HI (match_operand:V4QI 1 "register_operand" "r"))
      (zero_extend:V4HI (match_operand:V4QI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pwavgu.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwavgs_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
    (truncate:V4QI (ashiftrt:V4HI (plus:V4HI 
      (sign_extend:V4HI (match_operand:V4QI 1 "register_operand" "r"))
      (sign_extend:V4HI (match_operand:V4QI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pwavgs.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "subv4qi3"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
    (minus:V4QI 
      (match_operand:V4QI 1 "register_operand" "r")
      (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsub.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "ussubv4qi3"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
    (us_minus:V4QI 
      (match_operand:V4QI 1 "register_operand" "r")
      (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsubus.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "sssubv4qi3"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
    (ss_minus:V4QI 
      (match_operand:V4QI 1 "register_operand" "r")
      (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsubss.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsubhu_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
    (truncate:V4QI (lshiftrt:V4HI (minus:V4HI 
      (zero_extend:V4HI (match_operand:V4QI 1 "register_operand" "r"))
      (zero_extend:V4HI (match_operand:V4QI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pwsubhu.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsubhs_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
    (truncate:V4QI (ashiftrt:V4HI (minus:V4HI 
      (sign_extend:V4HI (match_operand:V4QI 1 "register_operand" "r"))
      (sign_extend:V4HI (match_operand:V4QI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pwsubhs.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh1add_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
    (plus:V4QI 
      (ashift:V4QI (match_operand:V4QI 1 "register_operand" "r") (const_int 1))
      (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsh1add.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh2add_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
    (plus:V4QI 
      (ashift:V4QI (match_operand:V4QI 1 "register_operand" "r") (const_int 2))
      (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsh2add.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh3add_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
    (plus:V4QI 
      (ashift:V4QI (match_operand:V4QI 1 "register_operand" "r") (const_int 3))
      (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsh3add.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "addv2hi3"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
    (plus:V2HI 
      (match_operand:V2HI 1 "register_operand" "r")
      (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwadd.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "usaddv2hi3"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
    (us_plus:V2HI 
      (match_operand:V2HI 1 "register_operand" "r")
      (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwaddus.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "ssaddv2hi3"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
    (ss_plus:V2HI 
      (match_operand:V2HI 1 "register_operand" "r")
      (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwaddss.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwavgu_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
    (truncate:V2HI (lshiftrt:V2SI (plus:V2SI 
      (zero_extend:V2SI (match_operand:V2HI 1 "register_operand" "r"))
      (zero_extend:V2SI (match_operand:V2HI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pwavgu.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwavgs_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
    (truncate:V2HI (ashiftrt:V2SI (plus:V2SI 
      (sign_extend:V2SI (match_operand:V2HI 1 "register_operand" "r"))
      (sign_extend:V2SI (match_operand:V2HI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pwavgs.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "subv2hi3"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
    (minus:V2HI 
      (match_operand:V2HI 1 "register_operand" "r")
      (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsub.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "ussubv2hi3"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
    (us_minus:V2HI 
      (match_operand:V2HI 1 "register_operand" "r")
      (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsubus.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "sssubv2hi3"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
    (ss_minus:V2HI 
      (match_operand:V2HI 1 "register_operand" "r")
      (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsubss.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsubhu_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
    (truncate:V2HI (lshiftrt:V2SI (minus:V2SI 
      (zero_extend:V2SI (match_operand:V2HI 1 "register_operand" "r"))
      (zero_extend:V2SI (match_operand:V2HI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pwsubhu.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsubhs_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
    (truncate:V2HI (ashiftrt:V2SI (minus:V2SI 
      (sign_extend:V2SI (match_operand:V2HI 1 "register_operand" "r"))
      (sign_extend:V2SI (match_operand:V2HI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pwsubhs.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh1add_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
    (plus:V2HI 
      (ashift:V2HI (match_operand:V2HI 1 "register_operand" "r") (const_int 1))
      (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsh1add.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh2add_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
    (plus:V2HI 
      (ashift:V2HI (match_operand:V2HI 1 "register_operand" "r") (const_int 2))
      (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsh2add.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh3add_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
    (plus:V2HI 
      (ashift:V2HI (match_operand:V2HI 1 "register_operand" "r") (const_int 3))
      (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsh3add.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwadd_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (plus:SI 
      (match_operand:SI 1 "register_operand" "r")
      (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwadd.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "usaddsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (us_plus:SI 
      (match_operand:SI 1 "register_operand" "r")
      (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwaddus.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "ssaddsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (ss_plus:SI 
      (match_operand:SI 1 "register_operand" "r")
      (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwaddss.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwavgu_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (truncate:SI (lshiftrt:DI (plus:DI 
      (zero_extend:DI (match_operand:SI 1 "register_operand" "r"))
      (zero_extend:DI (match_operand:SI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pwavgu.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwavgs_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (truncate:SI (ashiftrt:DI (plus:DI 
      (sign_extend:DI (match_operand:SI 1 "register_operand" "r"))
      (sign_extend:DI (match_operand:SI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pwavgs.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsub_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (minus:SI 
      (match_operand:SI 1 "register_operand" "r")
      (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsub.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "ussubsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (us_minus:SI 
      (match_operand:SI 1 "register_operand" "r")
      (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsubus.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "sssubsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (ss_minus:SI 
      (match_operand:SI 1 "register_operand" "r")
      (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsubss.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsubhu_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (truncate:SI (lshiftrt:DI (minus:DI 
      (zero_extend:DI (match_operand:SI 1 "register_operand" "r"))
      (zero_extend:DI (match_operand:SI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pwsubhu.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsubhs_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (truncate:SI (ashiftrt:DI (minus:DI 
      (sign_extend:DI (match_operand:SI 1 "register_operand" "r"))
      (sign_extend:DI (match_operand:SI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pwsubhs.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh1add_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (plus:SI 
      (ashift:SI (match_operand:SI 1 "register_operand" "r") (const_int 1))
      (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsh1add.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh2add_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (plus:SI 
      (ashift:SI (match_operand:SI 1 "register_operand" "r") (const_int 2))
      (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsh2add.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh3add_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (plus:SI 
      (ashift:SI (match_operand:SI 1 "register_operand" "r") (const_int 3))
      (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsh3add.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "addv8qi3"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
    (plus:V8QI 
      (match_operand:V8QI 1 "register_operand" "r")
      (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdadd.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "usaddv8qi3"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
    (us_plus:V8QI 
      (match_operand:V8QI 1 "register_operand" "r")
      (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdaddus.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "ssaddv8qi3"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
    (ss_plus:V8QI 
      (match_operand:V8QI 1 "register_operand" "r")
      (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdaddss.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdavgu_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
    (truncate:V8QI (lshiftrt:V8HI (plus:V8HI 
      (zero_extend:V8HI (match_operand:V8QI 1 "register_operand" "r"))
      (zero_extend:V8HI (match_operand:V8QI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdavgu.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdavgs_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
    (truncate:V8QI (ashiftrt:V8HI (plus:V8HI 
      (sign_extend:V8HI (match_operand:V8QI 1 "register_operand" "r"))
      (sign_extend:V8HI (match_operand:V8QI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdavgs.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "subv8qi3"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
    (minus:V8QI 
      (match_operand:V8QI 1 "register_operand" "r")
      (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsub.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "ussubv8qi3"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
    (us_minus:V8QI 
      (match_operand:V8QI 1 "register_operand" "r")
      (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsubus.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "sssubv8qi3"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
    (ss_minus:V8QI 
      (match_operand:V8QI 1 "register_operand" "r")
      (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsubss.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsubhu_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
    (truncate:V8QI (lshiftrt:V8HI (minus:V8HI 
      (zero_extend:V8HI (match_operand:V8QI 1 "register_operand" "r"))
      (zero_extend:V8HI (match_operand:V8QI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhu.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsubhs_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
    (truncate:V8QI (ashiftrt:V8HI (minus:V8HI 
      (sign_extend:V8HI (match_operand:V8QI 1 "register_operand" "r"))
      (sign_extend:V8HI (match_operand:V8QI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhs.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh1add_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
    (plus:V8QI 
      (ashift:V8QI (match_operand:V8QI 1 "register_operand" "r") (const_int 1))
      (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh1add.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh2add_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
    (plus:V8QI 
      (ashift:V8QI (match_operand:V8QI 1 "register_operand" "r") (const_int 2))
      (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh2add.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh3add_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
    (plus:V8QI 
      (ashift:V8QI (match_operand:V8QI 1 "register_operand" "r") (const_int 3))
      (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh3add.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "addv4hi3"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
    (plus:V4HI 
      (match_operand:V4HI 1 "register_operand" "r")
      (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdadd.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "usaddv4hi3"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
    (us_plus:V4HI 
      (match_operand:V4HI 1 "register_operand" "r")
      (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdaddus.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "ssaddv4hi3"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
    (ss_plus:V4HI 
      (match_operand:V4HI 1 "register_operand" "r")
      (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdaddss.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdavgu_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
    (truncate:V4HI (lshiftrt:V4SI (plus:V4SI 
      (zero_extend:V4SI (match_operand:V4HI 1 "register_operand" "r"))
      (zero_extend:V4SI (match_operand:V4HI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdavgu.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdavgs_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
    (truncate:V4HI (ashiftrt:V4SI (plus:V4SI 
      (sign_extend:V4SI (match_operand:V4HI 1 "register_operand" "r"))
      (sign_extend:V4SI (match_operand:V4HI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdavgs.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "subv4hi3"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
    (minus:V4HI 
      (match_operand:V4HI 1 "register_operand" "r")
      (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsub.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "ussubv4hi3"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
    (us_minus:V4HI 
      (match_operand:V4HI 1 "register_operand" "r")
      (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsubus.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "sssubv4hi3"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
    (ss_minus:V4HI 
      (match_operand:V4HI 1 "register_operand" "r")
      (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsubss.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsubhu_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
    (truncate:V4HI (lshiftrt:V4SI (minus:V4SI 
      (zero_extend:V4SI (match_operand:V4HI 1 "register_operand" "r"))
      (zero_extend:V4SI (match_operand:V4HI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhu.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsubhs_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
    (truncate:V4HI (ashiftrt:V4SI (minus:V4SI 
      (sign_extend:V4SI (match_operand:V4HI 1 "register_operand" "r"))
      (sign_extend:V4SI (match_operand:V4HI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhs.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh1add_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
    (plus:V4HI 
      (ashift:V4HI (match_operand:V4HI 1 "register_operand" "r") (const_int 1))
      (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh1add.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh2add_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
    (plus:V4HI 
      (ashift:V4HI (match_operand:V4HI 1 "register_operand" "r") (const_int 2))
      (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh2add.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh3add_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
    (plus:V4HI 
      (ashift:V4HI (match_operand:V4HI 1 "register_operand" "r") (const_int 3))
      (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh3add.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "addv2si3"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (plus:V2SI 
      (match_operand:V2SI 1 "register_operand" "r")
      (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdadd.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "usaddv2si3"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (us_plus:V2SI 
      (match_operand:V2SI 1 "register_operand" "r")
      (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdaddus.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "ssaddv2si3"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (ss_plus:V2SI 
      (match_operand:V2SI 1 "register_operand" "r")
      (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdaddss.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdavgu_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (truncate:V2SI (lshiftrt:V2DI (plus:V2DI 
      (zero_extend:V2DI (match_operand:V2SI 1 "register_operand" "r"))
      (zero_extend:V2DI (match_operand:V2SI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdavgu.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdavgs_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (truncate:V2SI (ashiftrt:V2DI (plus:V2DI 
      (sign_extend:V2DI (match_operand:V2SI 1 "register_operand" "r"))
      (sign_extend:V2DI (match_operand:V2SI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdavgs.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "subv2si3"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (minus:V2SI 
      (match_operand:V2SI 1 "register_operand" "r")
      (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsub.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "ussubv2si3"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (us_minus:V2SI 
      (match_operand:V2SI 1 "register_operand" "r")
      (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsubus.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "sssubv2si3"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (ss_minus:V2SI 
      (match_operand:V2SI 1 "register_operand" "r")
      (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsubss.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsubhu_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (truncate:V2SI (lshiftrt:V2DI (minus:V2DI 
      (zero_extend:V2DI (match_operand:V2SI 1 "register_operand" "r"))
      (zero_extend:V2DI (match_operand:V2SI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhu.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsubhs_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (truncate:V2SI (ashiftrt:V2DI (minus:V2DI 
      (sign_extend:V2DI (match_operand:V2SI 1 "register_operand" "r"))
      (sign_extend:V2DI (match_operand:V2SI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhs.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh1add_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (plus:V2SI 
      (ashift:V2SI (match_operand:V2SI 1 "register_operand" "r") (const_int 1))
      (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh1add.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh2add_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (plus:V2SI 
      (ashift:V2SI (match_operand:V2SI 1 "register_operand" "r") (const_int 2))
      (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh2add.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh3add_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (plus:V2SI 
      (ashift:V2SI (match_operand:V2SI 1 "register_operand" "r") (const_int 3))
      (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh3add.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdadd_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (plus:DI 
      (match_operand:DI 1 "register_operand" "r")
      (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdadd.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "usadddi3"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (us_plus:DI 
      (match_operand:DI 1 "register_operand" "r")
      (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdaddus.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "ssadddi3"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (ss_plus:DI 
      (match_operand:DI 1 "register_operand" "r")
      (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdaddss.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdavgu_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (truncate:DI (lshiftrt:TI (plus:TI 
      (zero_extend:TI (match_operand:DI 1 "register_operand" "r"))
      (zero_extend:TI (match_operand:DI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdavgu.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdavgs_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (truncate:DI (ashiftrt:TI (plus:TI 
      (sign_extend:TI (match_operand:DI 1 "register_operand" "r"))
      (sign_extend:TI (match_operand:DI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdavgs.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsub_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (minus:DI 
      (match_operand:DI 1 "register_operand" "r")
      (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsub.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "ussubdi3"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (us_minus:DI 
      (match_operand:DI 1 "register_operand" "r")
      (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsubus.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "sssubdi3"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (ss_minus:DI 
      (match_operand:DI 1 "register_operand" "r")
      (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsubss.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsubhu_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (truncate:DI (lshiftrt:TI (minus:TI 
      (zero_extend:TI (match_operand:DI 1 "register_operand" "r"))
      (zero_extend:TI (match_operand:DI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhu.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsubhs_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (truncate:DI (ashiftrt:TI (minus:TI 
      (sign_extend:TI (match_operand:DI 1 "register_operand" "r"))
      (sign_extend:TI (match_operand:DI 2 "register_operand" "r"))) (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhs.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh1add_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (plus:DI 
      (ashift:DI (match_operand:DI 1 "register_operand" "r") (const_int 1))
      (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh1add.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh2add_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (plus:DI 
      (ashift:DI (match_operand:DI 1 "register_operand" "r") (const_int 2))
      (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh2add.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh3add_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (plus:DI 
      (ashift:DI (match_operand:DI 1 "register_operand" "r") (const_int 3))
      (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh3add.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

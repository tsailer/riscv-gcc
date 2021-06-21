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
     (truncate:V4QI
       (lshiftrt:V4HI
         (plus:V4HI
           (zero_extend:V4HI
             (match_operand:V4QI 1 "register_operand" "r"))
           (zero_extend:V4HI
             (match_operand:V4QI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pwavgu.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwavgs_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (truncate:V4QI
       (ashiftrt:V4HI
         (plus:V4HI
           (sign_extend:V4HI
             (match_operand:V4QI 1 "register_operand" "r"))
           (sign_extend:V4HI
             (match_operand:V4QI 2 "register_operand" "r")))
         (const_int 1))))]
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
     (truncate:V4QI
       (lshiftrt:V4HI
         (minus:V4HI
           (zero_extend:V4HI
             (match_operand:V4QI 1 "register_operand" "r"))
           (zero_extend:V4HI
             (match_operand:V4QI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pwsubhu.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsubhs_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (truncate:V4QI
       (ashiftrt:V4HI
         (minus:V4HI
           (sign_extend:V4HI
             (match_operand:V4QI 1 "register_operand" "r"))
           (sign_extend:V4HI
             (match_operand:V4QI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pwsubhs.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh1add_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (plus:V4QI
       (ashift:V4QI
         (match_operand:V4QI 1 "register_operand" "r")
         (const_int 1))
       (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsh1add.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh2add_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (plus:V4QI
       (ashift:V4QI
         (match_operand:V4QI 1 "register_operand" "r")
         (const_int 2))
       (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsh2add.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh3add_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (plus:V4QI
       (ashift:V4QI
         (match_operand:V4QI 1 "register_operand" "r")
         (const_int 3))
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
     (truncate:V2HI
       (lshiftrt:V2SI
         (plus:V2SI
           (zero_extend:V2SI
             (match_operand:V2HI 1 "register_operand" "r"))
           (zero_extend:V2SI
             (match_operand:V2HI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pwavgu.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwavgs_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (truncate:V2HI
       (ashiftrt:V2SI
         (plus:V2SI
           (sign_extend:V2SI
             (match_operand:V2HI 1 "register_operand" "r"))
           (sign_extend:V2SI
             (match_operand:V2HI 2 "register_operand" "r")))
         (const_int 1))))]
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
     (truncate:V2HI
       (lshiftrt:V2SI
         (minus:V2SI
           (zero_extend:V2SI
             (match_operand:V2HI 1 "register_operand" "r"))
           (zero_extend:V2SI
             (match_operand:V2HI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pwsubhu.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsubhs_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (truncate:V2HI
       (ashiftrt:V2SI
         (minus:V2SI
           (sign_extend:V2SI
             (match_operand:V2HI 1 "register_operand" "r"))
           (sign_extend:V2SI
             (match_operand:V2HI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pwsubhs.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh1add_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (plus:V2HI
       (ashift:V2HI
         (match_operand:V2HI 1 "register_operand" "r")
         (const_int 1))
       (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsh1add.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh2add_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (plus:V2HI
       (ashift:V2HI
         (match_operand:V2HI 1 "register_operand" "r")
         (const_int 2))
       (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsh2add.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh3add_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (plus:V2HI
       (ashift:V2HI
         (match_operand:V2HI 1 "register_operand" "r")
         (const_int 3))
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
     (truncate:SI
       (lshiftrt:DI
         (plus:DI
           (zero_extend:DI
             (match_operand:SI 1 "register_operand" "r"))
           (zero_extend:DI
             (match_operand:SI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pwavgu.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwavgs_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (truncate:SI
       (ashiftrt:DI
         (plus:DI
           (sign_extend:DI
             (match_operand:SI 1 "register_operand" "r"))
           (sign_extend:DI
             (match_operand:SI 2 "register_operand" "r")))
         (const_int 1))))]
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
     (truncate:SI
       (lshiftrt:DI
         (minus:DI
           (zero_extend:DI
             (match_operand:SI 1 "register_operand" "r"))
           (zero_extend:DI
             (match_operand:SI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pwsubhu.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsubhs_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (truncate:SI
       (ashiftrt:DI
         (minus:DI
           (sign_extend:DI
             (match_operand:SI 1 "register_operand" "r"))
           (sign_extend:DI
             (match_operand:SI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pwsubhs.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh1add_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (plus:SI
       (ashift:SI
         (match_operand:SI 1 "register_operand" "r")
         (const_int 1))
       (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsh1add.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh2add_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (plus:SI
       (ashift:SI
         (match_operand:SI 1 "register_operand" "r")
         (const_int 2))
       (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsh2add.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsh3add_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (plus:SI
       (ashift:SI
         (match_operand:SI 1 "register_operand" "r")
         (const_int 3))
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
     (truncate:V8QI
       (lshiftrt:V8HI
         (plus:V8HI
           (zero_extend:V8HI
             (match_operand:V8QI 1 "register_operand" "r"))
           (zero_extend:V8HI
             (match_operand:V8QI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pdavgu.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdavgs_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (truncate:V8QI
       (ashiftrt:V8HI
         (plus:V8HI
           (sign_extend:V8HI
             (match_operand:V8QI 1 "register_operand" "r"))
           (sign_extend:V8HI
             (match_operand:V8QI 2 "register_operand" "r")))
         (const_int 1))))]
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
     (truncate:V8QI
       (lshiftrt:V8HI
         (minus:V8HI
           (zero_extend:V8HI
             (match_operand:V8QI 1 "register_operand" "r"))
           (zero_extend:V8HI
             (match_operand:V8QI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhu.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsubhs_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (truncate:V8QI
       (ashiftrt:V8HI
         (minus:V8HI
           (sign_extend:V8HI
             (match_operand:V8QI 1 "register_operand" "r"))
           (sign_extend:V8HI
             (match_operand:V8QI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhs.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh1add_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (plus:V8QI
       (ashift:V8QI
         (match_operand:V8QI 1 "register_operand" "r")
         (const_int 1))
       (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh1add.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh2add_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (plus:V8QI
       (ashift:V8QI
         (match_operand:V8QI 1 "register_operand" "r")
         (const_int 2))
       (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh2add.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh3add_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (plus:V8QI
       (ashift:V8QI
         (match_operand:V8QI 1 "register_operand" "r")
         (const_int 3))
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
     (truncate:V4HI
       (lshiftrt:V4SI
         (plus:V4SI
           (zero_extend:V4SI
             (match_operand:V4HI 1 "register_operand" "r"))
           (zero_extend:V4SI
             (match_operand:V4HI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pdavgu.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdavgs_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (truncate:V4HI
       (ashiftrt:V4SI
         (plus:V4SI
           (sign_extend:V4SI
             (match_operand:V4HI 1 "register_operand" "r"))
           (sign_extend:V4SI
             (match_operand:V4HI 2 "register_operand" "r")))
         (const_int 1))))]
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
     (truncate:V4HI
       (lshiftrt:V4SI
         (minus:V4SI
           (zero_extend:V4SI
             (match_operand:V4HI 1 "register_operand" "r"))
           (zero_extend:V4SI
             (match_operand:V4HI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhu.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsubhs_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (truncate:V4HI
       (ashiftrt:V4SI
         (minus:V4SI
           (sign_extend:V4SI
             (match_operand:V4HI 1 "register_operand" "r"))
           (sign_extend:V4SI
             (match_operand:V4HI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhs.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh1add_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (plus:V4HI
       (ashift:V4HI
         (match_operand:V4HI 1 "register_operand" "r")
         (const_int 1))
       (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh1add.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh2add_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (plus:V4HI
       (ashift:V4HI
         (match_operand:V4HI 1 "register_operand" "r")
         (const_int 2))
       (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh2add.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh3add_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (plus:V4HI
       (ashift:V4HI
         (match_operand:V4HI 1 "register_operand" "r")
         (const_int 3))
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
     (truncate:V2SI
       (lshiftrt:V2DI
         (plus:V2DI
           (zero_extend:V2DI
             (match_operand:V2SI 1 "register_operand" "r"))
           (zero_extend:V2DI
             (match_operand:V2SI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pdavgu.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdavgs_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (truncate:V2SI
       (ashiftrt:V2DI
         (plus:V2DI
           (sign_extend:V2DI
             (match_operand:V2SI 1 "register_operand" "r"))
           (sign_extend:V2DI
             (match_operand:V2SI 2 "register_operand" "r")))
         (const_int 1))))]
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
     (truncate:V2SI
       (lshiftrt:V2DI
         (minus:V2DI
           (zero_extend:V2DI
             (match_operand:V2SI 1 "register_operand" "r"))
           (zero_extend:V2DI
             (match_operand:V2SI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhu.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsubhs_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (truncate:V2SI
       (ashiftrt:V2DI
         (minus:V2DI
           (sign_extend:V2DI
             (match_operand:V2SI 1 "register_operand" "r"))
           (sign_extend:V2DI
             (match_operand:V2SI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhs.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh1add_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (plus:V2SI
       (ashift:V2SI
         (match_operand:V2SI 1 "register_operand" "r")
         (const_int 1))
       (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh1add.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh2add_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (plus:V2SI
       (ashift:V2SI
         (match_operand:V2SI 1 "register_operand" "r")
         (const_int 2))
       (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh2add.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh3add_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (plus:V2SI
       (ashift:V2SI
         (match_operand:V2SI 1 "register_operand" "r")
         (const_int 3))
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
     (truncate:DI
       (lshiftrt:TI
         (plus:TI
           (zero_extend:TI
             (match_operand:DI 1 "register_operand" "r"))
           (zero_extend:TI
             (match_operand:DI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pdavgu.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdavgs_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (truncate:DI
       (ashiftrt:TI
         (plus:TI
           (sign_extend:TI
             (match_operand:DI 1 "register_operand" "r"))
           (sign_extend:TI
             (match_operand:DI 2 "register_operand" "r")))
         (const_int 1))))]
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
     (truncate:DI
       (lshiftrt:TI
         (minus:TI
           (zero_extend:TI
             (match_operand:DI 1 "register_operand" "r"))
           (zero_extend:TI
             (match_operand:DI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhu.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsubhs_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (truncate:DI
       (ashiftrt:TI
         (minus:TI
           (sign_extend:TI
             (match_operand:DI 1 "register_operand" "r"))
           (sign_extend:TI
             (match_operand:DI 2 "register_operand" "r")))
         (const_int 1))))]
  "TARGET_AMETHYST"
  "pdsubhs.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh1add_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (plus:DI
       (ashift:DI
         (match_operand:DI 1 "register_operand" "r")
         (const_int 1))
       (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh1add.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh2add_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (plus:DI
       (ashift:DI
         (match_operand:DI 1 "register_operand" "r")
         (const_int 2))
       (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh2add.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsh3add_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (plus:DI
       (ashift:DI
         (match_operand:DI 1 "register_operand" "r")
         (const_int 3))
       (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsh3add.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwhadd_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (vec_select:V4QI
       (vec_concat:V4QI
         (plus:V2QI
           (vec_select:V2QI
             (match_operand:V4QI 1 "register_operand" "r")
             (parallel [(const_int 0) (const_int 2)]))
           (vec_select:V2QI
             (match_dup 1)
             (parallel [(const_int 1) (const_int 3)])))
         (plus:V2QI
           (vec_select:V2QI
             (match_operand:V4QI 2 "register_operand" "r")
             (parallel [(const_int 0) (const_int 2)]))
           (vec_select:V2QI
             (match_dup 2)
             (parallel [(const_int 1) (const_int 3)]))))
       (parallel [(const_int 0) (const_int 2) (const_int 1) (const_int 3)])))]
  "TARGET_AMETHYST"
  "pwhadd.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwhsub_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (vec_select:V4QI
       (vec_concat:V4QI
         (minus:V2QI
           (vec_select:V2QI
             (match_operand:V4QI 1 "register_operand" "r")
             (parallel [(const_int 0) (const_int 2)]))
           (vec_select:V2QI
             (match_dup 1)
             (parallel [(const_int 1) (const_int 3)])))
         (minus:V2QI
           (vec_select:V2QI
             (match_operand:V4QI 2 "register_operand" "r")
             (parallel [(const_int 0) (const_int 2)]))
           (vec_select:V2QI
             (match_dup 2)
             (parallel [(const_int 1) (const_int 3)]))))
       (parallel [(const_int 0) (const_int 2) (const_int 1) (const_int 3)])))]
  "TARGET_AMETHYST"
  "pwhsub.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwhadd_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (vec_select:V2HI
       (vec_concat:V2HI
         (plus:HI
           (vec_select:HI
             (match_operand:V2HI 1 "register_operand" "r")
             (parallel [(const_int 0)]))
           (vec_select:HI
             (match_dup 1)
             (parallel [(const_int 1)])))
         (plus:HI
           (vec_select:HI
             (match_operand:V2HI 2 "register_operand" "r")
             (parallel [(const_int 0)]))
           (vec_select:HI
             (match_dup 2)
             (parallel [(const_int 1)]))))
       (parallel [(const_int 0) (const_int 1)])))]
  "TARGET_AMETHYST"
  "pwhadd.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwhsub_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (vec_select:V2HI
       (vec_concat:V2HI
         (minus:HI
           (vec_select:HI
             (match_operand:V2HI 1 "register_operand" "r")
             (parallel [(const_int 0)]))
           (vec_select:HI
             (match_dup 1)
             (parallel [(const_int 1)])))
         (minus:HI
           (vec_select:HI
             (match_operand:V2HI 2 "register_operand" "r")
             (parallel [(const_int 0)]))
           (vec_select:HI
             (match_dup 2)
             (parallel [(const_int 1)]))))
       (parallel [(const_int 0) (const_int 1)])))]
  "TARGET_AMETHYST"
  "pwhsub.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdhadd_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (vec_select:V8QI
       (vec_concat:V8QI
         (plus:V4QI
           (vec_select:V4QI
             (match_operand:V8QI 1 "register_operand" "r")
             (parallel [(const_int 0) (const_int 2) (const_int 4) (const_int 6)]))
           (vec_select:V4QI
             (match_dup 1)
             (parallel [(const_int 1) (const_int 3) (const_int 5) (const_int 7)])))
         (plus:V4QI
           (vec_select:V4QI
             (match_operand:V8QI 2 "register_operand" "r")
             (parallel [(const_int 0) (const_int 2) (const_int 4) (const_int 6)]))
           (vec_select:V4QI
             (match_dup 2)
             (parallel [(const_int 1) (const_int 3) (const_int 5) (const_int 7)]))))
       (parallel [(const_int 0) (const_int 4) (const_int 1) (const_int 5) (const_int 2) (const_int 6) (const_int 3) (const_int 7)])))]
  "TARGET_AMETHYST"
  "pdhadd.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdhsub_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (vec_select:V8QI
       (vec_concat:V8QI
         (minus:V4QI
           (vec_select:V4QI
             (match_operand:V8QI 1 "register_operand" "r")
             (parallel [(const_int 0) (const_int 2) (const_int 4) (const_int 6)]))
           (vec_select:V4QI
             (match_dup 1)
             (parallel [(const_int 1) (const_int 3) (const_int 5) (const_int 7)])))
         (minus:V4QI
           (vec_select:V4QI
             (match_operand:V8QI 2 "register_operand" "r")
             (parallel [(const_int 0) (const_int 2) (const_int 4) (const_int 6)]))
           (vec_select:V4QI
             (match_dup 2)
             (parallel [(const_int 1) (const_int 3) (const_int 5) (const_int 7)]))))
       (parallel [(const_int 0) (const_int 4) (const_int 1) (const_int 5) (const_int 2) (const_int 6) (const_int 3) (const_int 7)])))]
  "TARGET_AMETHYST"
  "pdhsub.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdhadd_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (vec_select:V4HI
       (vec_concat:V4HI
         (plus:V2HI
           (vec_select:V2HI
             (match_operand:V4HI 1 "register_operand" "r")
             (parallel [(const_int 0) (const_int 2)]))
           (vec_select:V2HI
             (match_dup 1)
             (parallel [(const_int 1) (const_int 3)])))
         (plus:V2HI
           (vec_select:V2HI
             (match_operand:V4HI 2 "register_operand" "r")
             (parallel [(const_int 0) (const_int 2)]))
           (vec_select:V2HI
             (match_dup 2)
             (parallel [(const_int 1) (const_int 3)]))))
       (parallel [(const_int 0) (const_int 2) (const_int 1) (const_int 3)])))]
  "TARGET_AMETHYST"
  "pdhadd.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdhsub_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (vec_select:V4HI
       (vec_concat:V4HI
         (minus:V2HI
           (vec_select:V2HI
             (match_operand:V4HI 1 "register_operand" "r")
             (parallel [(const_int 0) (const_int 2)]))
           (vec_select:V2HI
             (match_dup 1)
             (parallel [(const_int 1) (const_int 3)])))
         (minus:V2HI
           (vec_select:V2HI
             (match_operand:V4HI 2 "register_operand" "r")
             (parallel [(const_int 0) (const_int 2)]))
           (vec_select:V2HI
             (match_dup 2)
             (parallel [(const_int 1) (const_int 3)]))))
       (parallel [(const_int 0) (const_int 2) (const_int 1) (const_int 3)])))]
  "TARGET_AMETHYST"
  "pdhsub.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdhadd_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (vec_select:V2SI
       (vec_concat:V2SI
         (plus:SI
           (vec_select:SI
             (match_operand:V2SI 1 "register_operand" "r")
             (parallel [(const_int 0)]))
           (vec_select:SI
             (match_dup 1)
             (parallel [(const_int 1)])))
         (plus:SI
           (vec_select:SI
             (match_operand:V2SI 2 "register_operand" "r")
             (parallel [(const_int 0)]))
           (vec_select:SI
             (match_dup 2)
             (parallel [(const_int 1)]))))
       (parallel [(const_int 0) (const_int 1)])))]
  "TARGET_AMETHYST"
  "pdhadd.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdhsub_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (vec_select:V2SI
       (vec_concat:V2SI
         (minus:SI
           (vec_select:SI
             (match_operand:V2SI 1 "register_operand" "r")
             (parallel [(const_int 0)]))
           (vec_select:SI
             (match_dup 1)
             (parallel [(const_int 1)])))
         (minus:SI
           (vec_select:SI
             (match_operand:V2SI 2 "register_operand" "r")
             (parallel [(const_int 0)]))
           (vec_select:SI
             (match_dup 2)
             (parallel [(const_int 1)]))))
       (parallel [(const_int 0) (const_int 1)])))]
  "TARGET_AMETHYST"
  "pdhsub.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwslt_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (lt:V4QI
       (match_operand:V4QI 1 "register_operand" "r")
       (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwslt.b\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsltm_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (if_then_else:V4QI
       (lt:V4QI
         (match_operand:V4QI 1 "register_operand" "r")
         (match_operand:V4QI 2 "register_operand" "r"))
       (const_int -1)
       (const_int 0)))]
  "TARGET_AMETHYST"
  "pwsltm.b\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsltu_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (ltu:V4QI
       (match_operand:V4QI 1 "register_operand" "r")
       (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsltu.b\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsltum_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (if_then_else:V4QI
       (ltu:V4QI
         (match_operand:V4QI 1 "register_operand" "r")
         (match_operand:V4QI 2 "register_operand" "r"))
       (const_int -1)
       (const_int 0)))]
  "TARGET_AMETHYST"
  "pwsltum.b\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwslt_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (lt:V2HI
       (match_operand:V2HI 1 "register_operand" "r")
       (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwslt.h\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsltm_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (if_then_else:V2HI
       (lt:V2HI
         (match_operand:V2HI 1 "register_operand" "r")
         (match_operand:V2HI 2 "register_operand" "r"))
       (const_int -1)
       (const_int 0)))]
  "TARGET_AMETHYST"
  "pwsltm.h\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsltu_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ltu:V2HI
       (match_operand:V2HI 1 "register_operand" "r")
       (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsltu.h\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsltum_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (if_then_else:V2HI
       (ltu:V2HI
         (match_operand:V2HI 1 "register_operand" "r")
         (match_operand:V2HI 2 "register_operand" "r"))
       (const_int -1)
       (const_int 0)))]
  "TARGET_AMETHYST"
  "pwsltum.h\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwslt_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (lt:SI
       (match_operand:SI 1 "register_operand" "r")
       (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwslt.w\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsltm_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (if_then_else:SI
       (lt:SI
         (match_operand:SI 1 "register_operand" "r")
         (match_operand:SI 2 "register_operand" "r"))
       (const_int -1)
       (const_int 0)))]
  "TARGET_AMETHYST"
  "pwsltm.w\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsltu_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ltu:SI
       (match_operand:SI 1 "register_operand" "r")
       (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsltu.w\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsltum_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (if_then_else:SI
       (ltu:SI
         (match_operand:SI 1 "register_operand" "r")
         (match_operand:SI 2 "register_operand" "r"))
       (const_int -1)
       (const_int 0)))]
  "TARGET_AMETHYST"
  "pwsltum.w\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdslt_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (lt:V8QI
       (match_operand:V8QI 1 "register_operand" "r")
       (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdslt.b\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsltm_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (if_then_else:V8QI
       (lt:V8QI
         (match_operand:V8QI 1 "register_operand" "r")
         (match_operand:V8QI 2 "register_operand" "r"))
       (const_int -1)
       (const_int 0)))]
  "TARGET_AMETHYST"
  "pdsltm.b\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsltu_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (ltu:V8QI
       (match_operand:V8QI 1 "register_operand" "r")
       (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsltu.b\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsltum_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (if_then_else:V8QI
       (ltu:V8QI
         (match_operand:V8QI 1 "register_operand" "r")
         (match_operand:V8QI 2 "register_operand" "r"))
       (const_int -1)
       (const_int 0)))]
  "TARGET_AMETHYST"
  "pdsltum.b\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdslt_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (lt:V4HI
       (match_operand:V4HI 1 "register_operand" "r")
       (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdslt.h\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsltm_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (if_then_else:V4HI
       (lt:V4HI
         (match_operand:V4HI 1 "register_operand" "r")
         (match_operand:V4HI 2 "register_operand" "r"))
       (const_int -1)
       (const_int 0)))]
  "TARGET_AMETHYST"
  "pdsltm.h\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsltu_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (ltu:V4HI
       (match_operand:V4HI 1 "register_operand" "r")
       (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsltu.h\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsltum_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (if_then_else:V4HI
       (ltu:V4HI
         (match_operand:V4HI 1 "register_operand" "r")
         (match_operand:V4HI 2 "register_operand" "r"))
       (const_int -1)
       (const_int 0)))]
  "TARGET_AMETHYST"
  "pdsltum.h\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdslt_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (lt:V2SI
       (match_operand:V2SI 1 "register_operand" "r")
       (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdslt.w\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsltm_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (if_then_else:V2SI
       (lt:V2SI
         (match_operand:V2SI 1 "register_operand" "r")
         (match_operand:V2SI 2 "register_operand" "r"))
       (const_int -1)
       (const_int 0)))]
  "TARGET_AMETHYST"
  "pdsltm.w\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsltu_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ltu:V2SI
       (match_operand:V2SI 1 "register_operand" "r")
       (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsltu.w\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsltum_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (if_then_else:V2SI
       (ltu:V2SI
         (match_operand:V2SI 1 "register_operand" "r")
         (match_operand:V2SI 2 "register_operand" "r"))
       (const_int -1)
       (const_int 0)))]
  "TARGET_AMETHYST"
  "pdsltum.w\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdslt_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (lt:DI
       (match_operand:DI 1 "register_operand" "r")
       (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdslt.d\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsltm_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (if_then_else:DI
       (lt:DI
         (match_operand:DI 1 "register_operand" "r")
         (match_operand:DI 2 "register_operand" "r"))
       (const_int -1)
       (const_int 0)))]
  "TARGET_AMETHYST"
  "pdsltm.d\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsltu_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (ltu:DI
       (match_operand:DI 1 "register_operand" "r")
       (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsltu.d\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsltum_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (if_then_else:DI
       (ltu:DI
         (match_operand:DI 1 "register_operand" "r")
         (match_operand:DI 2 "register_operand" "r"))
       (const_int -1)
       (const_int 0)))]
  "TARGET_AMETHYST"
  "pdsltum.d\t%0,%1,%2"
  [(set_attr "type" "slt")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmin_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (smin:V4QI
       (match_operand:V4QI 1 "register_operand" "r")
       (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwmin.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmax_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (smax:V4QI
       (match_operand:V4QI 1 "register_operand" "r")
       (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwmax.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwminu_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (umin:V4QI
       (match_operand:V4QI 1 "register_operand" "r")
       (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwminu.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmaxu_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (umax:V4QI
       (match_operand:V4QI 1 "register_operand" "r")
       (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwmaxu.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmin_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (smin:V2HI
       (match_operand:V2HI 1 "register_operand" "r")
       (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwmin.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmax_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (smax:V2HI
       (match_operand:V2HI 1 "register_operand" "r")
       (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwmax.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwminu_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (umin:V2HI
       (match_operand:V2HI 1 "register_operand" "r")
       (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwminu.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmaxu_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (umax:V2HI
       (match_operand:V2HI 1 "register_operand" "r")
       (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwmaxu.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmin_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (smin:SI
       (match_operand:SI 1 "register_operand" "r")
       (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwmin.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmax_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (smax:SI
       (match_operand:SI 1 "register_operand" "r")
       (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwmax.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwminu_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (umin:SI
       (match_operand:SI 1 "register_operand" "r")
       (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwminu.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmaxu_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (umax:SI
       (match_operand:SI 1 "register_operand" "r")
       (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwmaxu.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmin_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (smin:V8QI
       (match_operand:V8QI 1 "register_operand" "r")
       (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdmin.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmax_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (smax:V8QI
       (match_operand:V8QI 1 "register_operand" "r")
       (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdmax.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdminu_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (umin:V8QI
       (match_operand:V8QI 1 "register_operand" "r")
       (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdminu.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmaxu_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (umax:V8QI
       (match_operand:V8QI 1 "register_operand" "r")
       (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdmaxu.b\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmin_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (smin:V4HI
       (match_operand:V4HI 1 "register_operand" "r")
       (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdmin.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmax_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (smax:V4HI
       (match_operand:V4HI 1 "register_operand" "r")
       (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdmax.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdminu_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (umin:V4HI
       (match_operand:V4HI 1 "register_operand" "r")
       (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdminu.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmaxu_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (umax:V4HI
       (match_operand:V4HI 1 "register_operand" "r")
       (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdmaxu.h\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmin_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (smin:V2SI
       (match_operand:V2SI 1 "register_operand" "r")
       (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdmin.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmax_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (smax:V2SI
       (match_operand:V2SI 1 "register_operand" "r")
       (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdmax.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdminu_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (umin:V2SI
       (match_operand:V2SI 1 "register_operand" "r")
       (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdminu.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmaxu_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (umax:V2SI
       (match_operand:V2SI 1 "register_operand" "r")
       (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdmaxu.w\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmin_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (smin:DI
       (match_operand:DI 1 "register_operand" "r")
       (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdmin.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmax_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (smax:DI
       (match_operand:DI 1 "register_operand" "r")
       (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdmax.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdminu_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (umin:DI
       (match_operand:DI 1 "register_operand" "r")
       (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdminu.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmaxu_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (umax:DI
       (match_operand:DI 1 "register_operand" "r")
       (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdmaxu.d\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwand"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (and:SI
       (match_operand:SI 1 "register_operand" "r")
       (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwand\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwor"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ior:SI
       (match_operand:SI 1 "register_operand" "r")
       (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwor\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwxor"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (xor:SI
       (match_operand:SI 1 "register_operand" "r")
       (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwxor\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwandn"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (and:SI
       (not:SI
         (match_operand:SI 2 "register_operand" "r"))
       (match_operand:SI 1 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwandn\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pworn"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ior:SI
       (not:SI
         (match_operand:SI 2 "register_operand" "r"))
       (match_operand:SI 1 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pworn\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwxnor"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (not:SI
       (xor:SI
         (match_operand:SI 1 "register_operand" "r")
         (match_operand:SI 2 "register_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwxnor\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdand"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (and:DI
       (match_operand:DI 1 "register_operand" "r")
       (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdand\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdor"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (ior:DI
       (match_operand:DI 1 "register_operand" "r")
       (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdor\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdxor"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (xor:DI
       (match_operand:DI 1 "register_operand" "r")
       (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdxor\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdandn"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (and:DI
       (not:DI
         (match_operand:DI 2 "register_operand" "r"))
       (match_operand:DI 1 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdandn\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdorn"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (ior:DI
       (not:DI
         (match_operand:DI 2 "register_operand" "r"))
       (match_operand:DI 1 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdorn\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdxnor"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (not:DI
       (xor:DI
         (match_operand:DI 1 "register_operand" "r")
         (match_operand:DI 2 "register_operand" "r"))))]
  "TARGET_AMETHYST"
  "pdxnor\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "ashlv4qi3"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (ashift:V4QI
       (match_operand:V4QI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsll.b\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "lshrv4qi3"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (lshiftrt:V4QI
       (match_operand:V4QI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsrl.b\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "ashrv4qi3"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (ashiftrt:V4QI
       (match_operand:V4QI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsra.b\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwslo_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (not:V4QI
       (ashift:V4QI
         (not:V4QI
           (match_operand:V4QI 1 "register_operand" "r"))
         (match_operand:QI 2 "arith_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwslo.b\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsro_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (not:V4QI
       (lshiftrt:V4QI
         (not:V4QI
           (match_operand:V4QI 1 "register_operand" "r"))
         (match_operand:QI 2 "arith_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwsro.b\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "rotlv4qi3"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (rotate:V4QI
       (match_operand:V4QI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pwrol.b\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "rotrv4qi3"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (rotatert:V4QI
       (match_operand:V4QI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pwror.b\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "ashlv2hi3"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ashift:V2HI
       (match_operand:V2HI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsll.h\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "lshrv2hi3"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (lshiftrt:V2HI
       (match_operand:V2HI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsrl.h\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "ashrv2hi3"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ashiftrt:V2HI
       (match_operand:V2HI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsra.h\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwslo_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (not:V2HI
       (ashift:V2HI
         (not:V2HI
           (match_operand:V2HI 1 "register_operand" "r"))
         (match_operand:QI 2 "arith_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwslo.h\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsro_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (not:V2HI
       (lshiftrt:V2HI
         (not:V2HI
           (match_operand:V2HI 1 "register_operand" "r"))
         (match_operand:QI 2 "arith_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwsro.h\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "rotlv2hi3"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (rotate:V2HI
       (match_operand:V2HI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pwrol.h\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "rotrv2hi3"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (rotatert:V2HI
       (match_operand:V2HI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pwror.h\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsll_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ashift:SI
       (match_operand:SI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsll.w\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsrl_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (lshiftrt:SI
       (match_operand:SI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsrl.w\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsra_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ashiftrt:SI
       (match_operand:SI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pwsra.w\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwslo_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (not:SI
       (ashift:SI
         (not:SI
           (match_operand:SI 1 "register_operand" "r"))
         (match_operand:QI 2 "arith_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwslo.w\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwsro_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (not:SI
       (lshiftrt:SI
         (not:SI
           (match_operand:SI 1 "register_operand" "r"))
         (match_operand:QI 2 "arith_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwsro.w\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwrol_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (rotate:SI
       (match_operand:SI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pwrol.w\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwror_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (rotatert:SI
       (match_operand:SI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pwror.w\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

(define_insn "ashlv8qi3"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (ashift:V8QI
       (match_operand:V8QI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsll.b\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "lshrv8qi3"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (lshiftrt:V8QI
       (match_operand:V8QI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsrl.b\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "ashrv8qi3"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (ashiftrt:V8QI
       (match_operand:V8QI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsra.b\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdslo_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (not:V8QI
       (ashift:V8QI
         (not:V8QI
           (match_operand:V8QI 1 "register_operand" "r"))
         (match_operand:QI 2 "arith_operand" "r"))))]
  "TARGET_AMETHYST"
  "pdslo.b\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsro_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (not:V8QI
       (lshiftrt:V8QI
         (not:V8QI
           (match_operand:V8QI 1 "register_operand" "r"))
         (match_operand:QI 2 "arith_operand" "r"))))]
  "TARGET_AMETHYST"
  "pdsro.b\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "rotlv8qi3"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (rotate:V8QI
       (match_operand:V8QI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdrol.b\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "rotrv8qi3"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (rotatert:V8QI
       (match_operand:V8QI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdror.b\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "ashlv4hi3"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (ashift:V4HI
       (match_operand:V4HI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsll.h\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "lshrv4hi3"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (lshiftrt:V4HI
       (match_operand:V4HI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsrl.h\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "ashrv4hi3"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (ashiftrt:V4HI
       (match_operand:V4HI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsra.h\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdslo_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (not:V4HI
       (ashift:V4HI
         (not:V4HI
           (match_operand:V4HI 1 "register_operand" "r"))
         (match_operand:QI 2 "arith_operand" "r"))))]
  "TARGET_AMETHYST"
  "pdslo.h\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsro_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (not:V4HI
       (lshiftrt:V4HI
         (not:V4HI
           (match_operand:V4HI 1 "register_operand" "r"))
         (match_operand:QI 2 "arith_operand" "r"))))]
  "TARGET_AMETHYST"
  "pdsro.h\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "rotlv4hi3"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (rotate:V4HI
       (match_operand:V4HI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdrol.h\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "rotrv4hi3"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (rotatert:V4HI
       (match_operand:V4HI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdror.h\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "ashlv2si3"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ashift:V2SI
       (match_operand:V2SI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsll.w\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "lshrv2si3"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (lshiftrt:V2SI
       (match_operand:V2SI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsrl.w\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "ashrv2si3"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ashiftrt:V2SI
       (match_operand:V2SI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsra.w\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdslo_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (not:V2SI
       (ashift:V2SI
         (not:V2SI
           (match_operand:V2SI 1 "register_operand" "r"))
         (match_operand:QI 2 "arith_operand" "r"))))]
  "TARGET_AMETHYST"
  "pdslo.w\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsro_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (not:V2SI
       (lshiftrt:V2SI
         (not:V2SI
           (match_operand:V2SI 1 "register_operand" "r"))
         (match_operand:QI 2 "arith_operand" "r"))))]
  "TARGET_AMETHYST"
  "pdsro.w\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "rotlv2si3"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (rotate:V2SI
       (match_operand:V2SI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdrol.w\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "rotrv2si3"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (rotatert:V2SI
       (match_operand:V2SI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdror.w\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsll_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (ashift:DI
       (match_operand:DI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsll.d\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsrl_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (lshiftrt:DI
       (match_operand:DI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsrl.d\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsra_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (ashiftrt:DI
       (match_operand:DI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdsra.d\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdslo_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (not:DI
       (ashift:DI
         (not:DI
           (match_operand:DI 1 "register_operand" "r"))
         (match_operand:QI 2 "arith_operand" "r"))))]
  "TARGET_AMETHYST"
  "pdslo.d\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdsro_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (not:DI
       (lshiftrt:DI
         (not:DI
           (match_operand:DI 1 "register_operand" "r"))
         (match_operand:QI 2 "arith_operand" "r"))))]
  "TARGET_AMETHYST"
  "pdsro.d\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdrol_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (rotate:DI
       (match_operand:DI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdrol.d\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdror_d"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (rotatert:DI
       (match_operand:DI 1 "register_operand" "r")
       (match_operand:QI 2 "arith_operand" "r")))]
  "TARGET_AMETHYST"
  "pdror.d\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "DI")])

(define_insn "smulv4qi3_highpart"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (truncate:V4QI
       (lshiftrt:V4HI
         (mult:V4HI
           (sign_extend:V4HI
             (match_operand:V4QI 1 "register_operand" "r"))
           (sign_extend:V4HI
             (match_operand:V4QI 2 "register_operand" "r")))
         (const_int 8))))]
  "TARGET_AMETHYST"
  "pwmulsst.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "mulv4qi3"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (mult:V4QI
       (match_operand:V4QI 1 "register_operand" "r")
       (match_operand:V4QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwmulssb.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulssbqu_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (us_truncate:V4QI
       (mult:V4HI
         (sign_extend:V4HI
           (match_operand:V4QI 1 "register_operand" "r"))
         (sign_extend:V4HI
           (match_operand:V4QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulssbqu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "ssmulv4qi3"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (ss_truncate:V4QI
       (mult:V4HI
         (sign_extend:V4HI
           (match_operand:V4QI 1 "register_operand" "r"))
         (sign_extend:V4HI
           (match_operand:V4QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulssbqs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulsut_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (truncate:V4QI
       (lshiftrt:V4HI
         (mult:V4HI
           (sign_extend:V4HI
             (match_operand:V4QI 1 "register_operand" "r"))
           (sign_extend:V4HI
             (match_operand:V4QI 2 "register_operand" "r")))
         (const_int 8))))]
  "TARGET_AMETHYST"
  "pwmulsut.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulsub_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (truncate:V4QI
       (mult:V4HI
         (sign_extend:V4HI
           (match_operand:V4QI 1 "register_operand" "r"))
         (sign_extend:V4HI
           (match_operand:V4QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulsub.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulsubqu_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (us_truncate:V4QI
       (mult:V4HI
         (sign_extend:V4HI
           (match_operand:V4QI 1 "register_operand" "r"))
         (sign_extend:V4HI
           (match_operand:V4QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulsubqu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulsubqs_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (ss_truncate:V4QI
       (mult:V4HI
         (sign_extend:V4HI
           (match_operand:V4QI 1 "register_operand" "r"))
         (sign_extend:V4HI
           (match_operand:V4QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulsubqs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "umulv4qi3_highpart"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (truncate:V4QI
       (lshiftrt:V4HI
         (mult:V4HI
           (zero_extend:V4HI
             (match_operand:V4QI 1 "register_operand" "r"))
           (zero_extend:V4HI
             (match_operand:V4QI 2 "register_operand" "r")))
         (const_int 8))))]
  "TARGET_AMETHYST"
  "pwmuluut.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmuluub_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (truncate:V4QI
       (mult:V4HI
         (zero_extend:V4HI
           (match_operand:V4QI 1 "register_operand" "r"))
         (zero_extend:V4HI
           (match_operand:V4QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmuluub.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "usmulv4qi3"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (us_truncate:V4QI
       (mult:V4HI
         (zero_extend:V4HI
           (match_operand:V4QI 1 "register_operand" "r"))
         (zero_extend:V4HI
           (match_operand:V4QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmuluubqu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmuluubqs_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (ss_truncate:V4QI
       (mult:V4HI
         (zero_extend:V4HI
           (match_operand:V4QI 1 "register_operand" "r"))
         (zero_extend:V4HI
           (match_operand:V4QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmuluubqs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "smulv2hi3_highpart"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (truncate:V2HI
       (lshiftrt:V2SI
         (mult:V2SI
           (sign_extend:V2SI
             (match_operand:V2HI 1 "register_operand" "r"))
           (sign_extend:V2SI
             (match_operand:V2HI 2 "register_operand" "r")))
         (const_int 16))))]
  "TARGET_AMETHYST"
  "pwmulsst.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "mulv2hi3"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (mult:V2HI
       (match_operand:V2HI 1 "register_operand" "r")
       (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwmulssb.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulssbqu_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (us_truncate:V2HI
       (mult:V2SI
         (sign_extend:V2SI
           (match_operand:V2HI 1 "register_operand" "r"))
         (sign_extend:V2SI
           (match_operand:V2HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulssbqu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "ssmulv2hi3"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (mult:V2SI
         (sign_extend:V2SI
           (match_operand:V2HI 1 "register_operand" "r"))
         (sign_extend:V2SI
           (match_operand:V2HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulssbqs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulsut_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (truncate:V2HI
       (lshiftrt:V2SI
         (mult:V2SI
           (sign_extend:V2SI
             (match_operand:V2HI 1 "register_operand" "r"))
           (sign_extend:V2SI
             (match_operand:V2HI 2 "register_operand" "r")))
         (const_int 16))))]
  "TARGET_AMETHYST"
  "pwmulsut.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulsub_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (truncate:V2HI
       (mult:V2SI
         (sign_extend:V2SI
           (match_operand:V2HI 1 "register_operand" "r"))
         (sign_extend:V2SI
           (match_operand:V2HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulsub.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulsubqu_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (us_truncate:V2HI
       (mult:V2SI
         (sign_extend:V2SI
           (match_operand:V2HI 1 "register_operand" "r"))
         (sign_extend:V2SI
           (match_operand:V2HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulsubqu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulsubqs_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (mult:V2SI
         (sign_extend:V2SI
           (match_operand:V2HI 1 "register_operand" "r"))
         (sign_extend:V2SI
           (match_operand:V2HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulsubqs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "umulv2hi3_highpart"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (truncate:V2HI
       (lshiftrt:V2SI
         (mult:V2SI
           (zero_extend:V2SI
             (match_operand:V2HI 1 "register_operand" "r"))
           (zero_extend:V2SI
             (match_operand:V2HI 2 "register_operand" "r")))
         (const_int 16))))]
  "TARGET_AMETHYST"
  "pwmuluut.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmuluub_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (truncate:V2HI
       (mult:V2SI
         (zero_extend:V2SI
           (match_operand:V2HI 1 "register_operand" "r"))
         (zero_extend:V2SI
           (match_operand:V2HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmuluub.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "usmulv2hi3"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (us_truncate:V2HI
       (mult:V2SI
         (zero_extend:V2SI
           (match_operand:V2HI 1 "register_operand" "r"))
         (zero_extend:V2SI
           (match_operand:V2HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmuluubqu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmuluubqs_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (mult:V2SI
         (zero_extend:V2SI
           (match_operand:V2HI 1 "register_operand" "r"))
         (zero_extend:V2SI
           (match_operand:V2HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmuluubqs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulsst_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (truncate:SI
       (lshiftrt:DI
         (mult:DI
           (sign_extend:DI
             (match_operand:SI 1 "register_operand" "r"))
           (sign_extend:DI
             (match_operand:SI 2 "register_operand" "r")))
         (const_int 32))))]
  "TARGET_AMETHYST"
  "pwmulsst.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulssb_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (mult:SI
       (match_operand:SI 1 "register_operand" "r")
       (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pwmulssb.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulssbqu_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (us_truncate:SI
       (mult:DI
         (sign_extend:DI
           (match_operand:SI 1 "register_operand" "r"))
         (sign_extend:DI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulssbqu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "ssmulsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ss_truncate:SI
       (mult:DI
         (sign_extend:DI
           (match_operand:SI 1 "register_operand" "r"))
         (sign_extend:DI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulssbqs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulsut_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (truncate:SI
       (lshiftrt:DI
         (mult:DI
           (sign_extend:DI
             (match_operand:SI 1 "register_operand" "r"))
           (sign_extend:DI
             (match_operand:SI 2 "register_operand" "r")))
         (const_int 32))))]
  "TARGET_AMETHYST"
  "pwmulsut.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulsub_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (truncate:SI
       (mult:DI
         (sign_extend:DI
           (match_operand:SI 1 "register_operand" "r"))
         (sign_extend:DI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulsub.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulsubqu_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (us_truncate:SI
       (mult:DI
         (sign_extend:DI
           (match_operand:SI 1 "register_operand" "r"))
         (sign_extend:DI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulsubqu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulsubqs_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ss_truncate:SI
       (mult:DI
         (sign_extend:DI
           (match_operand:SI 1 "register_operand" "r"))
         (sign_extend:DI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulsubqs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmuluut_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (truncate:SI
       (lshiftrt:DI
         (mult:DI
           (zero_extend:DI
             (match_operand:SI 1 "register_operand" "r"))
           (zero_extend:DI
             (match_operand:SI 2 "register_operand" "r")))
         (const_int 32))))]
  "TARGET_AMETHYST"
  "pwmuluut.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmuluub_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (truncate:SI
       (mult:DI
         (zero_extend:DI
           (match_operand:SI 1 "register_operand" "r"))
         (zero_extend:DI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmuluub.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "usmulsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (us_truncate:SI
       (mult:DI
         (zero_extend:DI
           (match_operand:SI 1 "register_operand" "r"))
         (zero_extend:DI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmuluubqu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmuluubqs_w"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ss_truncate:SI
       (mult:DI
         (zero_extend:DI
           (match_operand:SI 1 "register_operand" "r"))
         (zero_extend:DI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmuluubqs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "smulv8qi3_highpart"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (truncate:V8QI
       (lshiftrt:V8HI
         (mult:V8HI
           (sign_extend:V8HI
             (match_operand:V8QI 1 "register_operand" "r"))
           (sign_extend:V8HI
             (match_operand:V8QI 2 "register_operand" "r")))
         (const_int 8))))]
  "TARGET_AMETHYST"
  "pdmulsst.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "mulv8qi3"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (mult:V8QI
       (match_operand:V8QI 1 "register_operand" "r")
       (match_operand:V8QI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdmulssb.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulssbqu_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (us_truncate:V8QI
       (mult:V8HI
         (sign_extend:V8HI
           (match_operand:V8QI 1 "register_operand" "r"))
         (sign_extend:V8HI
           (match_operand:V8QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmulssbqu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "ssmulv8qi3"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (ss_truncate:V8QI
       (mult:V8HI
         (sign_extend:V8HI
           (match_operand:V8QI 1 "register_operand" "r"))
         (sign_extend:V8HI
           (match_operand:V8QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmulssbqs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulsut_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (truncate:V8QI
       (lshiftrt:V8HI
         (mult:V8HI
           (sign_extend:V8HI
             (match_operand:V8QI 1 "register_operand" "r"))
           (sign_extend:V8HI
             (match_operand:V8QI 2 "register_operand" "r")))
         (const_int 8))))]
  "TARGET_AMETHYST"
  "pdmulsut.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulsub_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (truncate:V8QI
       (mult:V8HI
         (sign_extend:V8HI
           (match_operand:V8QI 1 "register_operand" "r"))
         (sign_extend:V8HI
           (match_operand:V8QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmulsub.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulsubqu_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (us_truncate:V8QI
       (mult:V8HI
         (sign_extend:V8HI
           (match_operand:V8QI 1 "register_operand" "r"))
         (sign_extend:V8HI
           (match_operand:V8QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmulsubqu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulsubqs_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (ss_truncate:V8QI
       (mult:V8HI
         (sign_extend:V8HI
           (match_operand:V8QI 1 "register_operand" "r"))
         (sign_extend:V8HI
           (match_operand:V8QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmulsubqs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "umulv8qi3_highpart"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (truncate:V8QI
       (lshiftrt:V8HI
         (mult:V8HI
           (zero_extend:V8HI
             (match_operand:V8QI 1 "register_operand" "r"))
           (zero_extend:V8HI
             (match_operand:V8QI 2 "register_operand" "r")))
         (const_int 8))))]
  "TARGET_AMETHYST"
  "pdmuluut.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmuluub_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (truncate:V8QI
       (mult:V8HI
         (zero_extend:V8HI
           (match_operand:V8QI 1 "register_operand" "r"))
         (zero_extend:V8HI
           (match_operand:V8QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmuluub.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "usmulv8qi3"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (us_truncate:V8QI
       (mult:V8HI
         (zero_extend:V8HI
           (match_operand:V8QI 1 "register_operand" "r"))
         (zero_extend:V8HI
           (match_operand:V8QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmuluubqu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmuluubqs_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (ss_truncate:V8QI
       (mult:V8HI
         (zero_extend:V8HI
           (match_operand:V8QI 1 "register_operand" "r"))
         (zero_extend:V8HI
           (match_operand:V8QI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmuluubqs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "smulv4hi3_highpart"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (truncate:V4HI
       (lshiftrt:V4SI
         (mult:V4SI
           (sign_extend:V4SI
             (match_operand:V4HI 1 "register_operand" "r"))
           (sign_extend:V4SI
             (match_operand:V4HI 2 "register_operand" "r")))
         (const_int 16))))]
  "TARGET_AMETHYST"
  "pdmulsst.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "mulv4hi3"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (mult:V4HI
       (match_operand:V4HI 1 "register_operand" "r")
       (match_operand:V4HI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdmulssb.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulssbqu_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (us_truncate:V4HI
       (mult:V4SI
         (sign_extend:V4SI
           (match_operand:V4HI 1 "register_operand" "r"))
         (sign_extend:V4SI
           (match_operand:V4HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmulssbqu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "ssmulv4hi3"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (ss_truncate:V4HI
       (mult:V4SI
         (sign_extend:V4SI
           (match_operand:V4HI 1 "register_operand" "r"))
         (sign_extend:V4SI
           (match_operand:V4HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmulssbqs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulsut_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (truncate:V4HI
       (lshiftrt:V4SI
         (mult:V4SI
           (sign_extend:V4SI
             (match_operand:V4HI 1 "register_operand" "r"))
           (sign_extend:V4SI
             (match_operand:V4HI 2 "register_operand" "r")))
         (const_int 16))))]
  "TARGET_AMETHYST"
  "pdmulsut.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulsub_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (truncate:V4HI
       (mult:V4SI
         (sign_extend:V4SI
           (match_operand:V4HI 1 "register_operand" "r"))
         (sign_extend:V4SI
           (match_operand:V4HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmulsub.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulsubqu_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (us_truncate:V4HI
       (mult:V4SI
         (sign_extend:V4SI
           (match_operand:V4HI 1 "register_operand" "r"))
         (sign_extend:V4SI
           (match_operand:V4HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmulsubqu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulsubqs_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (ss_truncate:V4HI
       (mult:V4SI
         (sign_extend:V4SI
           (match_operand:V4HI 1 "register_operand" "r"))
         (sign_extend:V4SI
           (match_operand:V4HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmulsubqs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "umulv4hi3_highpart"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (truncate:V4HI
       (lshiftrt:V4SI
         (mult:V4SI
           (zero_extend:V4SI
             (match_operand:V4HI 1 "register_operand" "r"))
           (zero_extend:V4SI
             (match_operand:V4HI 2 "register_operand" "r")))
         (const_int 16))))]
  "TARGET_AMETHYST"
  "pdmuluut.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmuluub_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (truncate:V4HI
       (mult:V4SI
         (zero_extend:V4SI
           (match_operand:V4HI 1 "register_operand" "r"))
         (zero_extend:V4SI
           (match_operand:V4HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmuluub.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "usmulv4hi3"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (us_truncate:V4HI
       (mult:V4SI
         (zero_extend:V4SI
           (match_operand:V4HI 1 "register_operand" "r"))
         (zero_extend:V4SI
           (match_operand:V4HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmuluubqu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmuluubqs_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (ss_truncate:V4HI
       (mult:V4SI
         (zero_extend:V4SI
           (match_operand:V4HI 1 "register_operand" "r"))
         (zero_extend:V4SI
           (match_operand:V4HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmuluubqs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "smulv2si3_highpart"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (truncate:V2SI
       (lshiftrt:V2DI
         (mult:V2DI
           (sign_extend:V2DI
             (match_operand:V2SI 1 "register_operand" "r"))
           (sign_extend:V2DI
             (match_operand:V2SI 2 "register_operand" "r")))
         (const_int 32))))]
  "TARGET_AMETHYST"
  "pdmulsst.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "mulv2si3"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (mult:V2SI
       (match_operand:V2SI 1 "register_operand" "r")
       (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_AMETHYST"
  "pdmulssb.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulssbqu_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (us_truncate:V2SI
       (mult:V2DI
         (sign_extend:V2DI
           (match_operand:V2SI 1 "register_operand" "r"))
         (sign_extend:V2DI
           (match_operand:V2SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmulssbqu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "ssmulv2si3"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (mult:V2DI
         (sign_extend:V2DI
           (match_operand:V2SI 1 "register_operand" "r"))
         (sign_extend:V2DI
           (match_operand:V2SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmulssbqs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulsut_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (truncate:V2SI
       (lshiftrt:V2DI
         (mult:V2DI
           (sign_extend:V2DI
             (match_operand:V2SI 1 "register_operand" "r"))
           (sign_extend:V2DI
             (match_operand:V2SI 2 "register_operand" "r")))
         (const_int 32))))]
  "TARGET_AMETHYST"
  "pdmulsut.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulsub_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (truncate:V2SI
       (mult:V2DI
         (sign_extend:V2DI
           (match_operand:V2SI 1 "register_operand" "r"))
         (sign_extend:V2DI
           (match_operand:V2SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmulsub.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulsubqu_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (us_truncate:V2SI
       (mult:V2DI
         (sign_extend:V2DI
           (match_operand:V2SI 1 "register_operand" "r"))
         (sign_extend:V2DI
           (match_operand:V2SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmulsubqu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulsubqs_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (mult:V2DI
         (sign_extend:V2DI
           (match_operand:V2SI 1 "register_operand" "r"))
         (sign_extend:V2DI
           (match_operand:V2SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmulsubqs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "umulv2si3_highpart"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (truncate:V2SI
       (lshiftrt:V2DI
         (mult:V2DI
           (zero_extend:V2DI
             (match_operand:V2SI 1 "register_operand" "r"))
           (zero_extend:V2DI
             (match_operand:V2SI 2 "register_operand" "r")))
         (const_int 32))))]
  "TARGET_AMETHYST"
  "pdmuluut.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmuluub_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (truncate:V2SI
       (mult:V2DI
         (zero_extend:V2DI
           (match_operand:V2SI 1 "register_operand" "r"))
         (zero_extend:V2DI
           (match_operand:V2SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmuluub.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "usmulv2si3"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (us_truncate:V2SI
       (mult:V2DI
         (zero_extend:V2DI
           (match_operand:V2SI 1 "register_operand" "r"))
         (zero_extend:V2DI
           (match_operand:V2SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmuluubqu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmuluubqs_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (mult:V2DI
         (zero_extend:V2DI
           (match_operand:V2SI 1 "register_operand" "r"))
         (zero_extend:V2DI
           (match_operand:V2SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pdmuluubqs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmulssw_b"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (mult:V4HI
       (sign_extend:V4HI
         (match_operand:V4QI 1 "register_operand" "r"))
       (sign_extend:V4HI
         (match_operand:V4QI 2 "register_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwmulssw.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmulsuw_b"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (mult:V4HI
       (sign_extend:V4HI
         (match_operand:V4QI 1 "register_operand" "r"))
       (sign_extend:V4HI
         (match_operand:V4QI 2 "register_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwmulsuw.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmuluuw_b"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (mult:V4HI
       (zero_extend:V4HI
         (match_operand:V4QI 1 "register_operand" "r"))
       (zero_extend:V4HI
         (match_operand:V4QI 2 "register_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwmuluuw.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmulssw_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (mult:V2SI
       (sign_extend:V2SI
         (match_operand:V2HI 1 "register_operand" "r"))
       (sign_extend:V2SI
         (match_operand:V2HI 2 "register_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwmulssw.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmulsuw_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (mult:V2SI
       (sign_extend:V2SI
         (match_operand:V2HI 1 "register_operand" "r"))
       (sign_extend:V2SI
         (match_operand:V2HI 2 "register_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwmulsuw.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmuluuw_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (mult:V2SI
       (zero_extend:V2SI
         (match_operand:V2HI 1 "register_operand" "r"))
       (zero_extend:V2SI
         (match_operand:V2HI 2 "register_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwmuluuw.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmulssw_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (mult:DI
       (sign_extend:DI
         (match_operand:SI 1 "register_operand" "r"))
       (sign_extend:DI
         (match_operand:SI 2 "register_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwmulssw.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmulsuw_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (mult:DI
       (sign_extend:DI
         (match_operand:SI 1 "register_operand" "r"))
       (sign_extend:DI
         (match_operand:SI 2 "register_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwmulsuw.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmuluuw_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (mult:DI
       (zero_extend:DI
         (match_operand:SI 1 "register_operand" "r"))
       (zero_extend:DI
         (match_operand:SI 2 "register_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwmuluuw.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmulcct_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (truncate:V4QI
       (lshiftrt:V4HI
         (plus:V4HI
           (mult:V4HI
             (sign_extend:V4HI
               (match_operand:V4QI 1 "register_operand" "r"))
             (sign_extend:V4HI
               (vec_select:V4QI
                 (match_operand:V4QI 2 "register_operand" "r")
                 (parallel [(const_int 0) (const_int 0) (const_int 2) (const_int 2)]))))
           (mult:V4HI
             (mult:V4HI
               (sign_extend:V4HI
                 (vec_select:V4QI
                   (match_dup 1)
                   (parallel [(const_int 1) (const_int 1) (const_int 3) (const_int 3)])))
               (sign_extend:V4HI
                 (match_dup 2)))
             (parallel [(const_int -1) (const_int 1) (const_int -1) (const_int 1)])))
         (const_int 8))))]
  "TARGET_AMETHYST"
  "pwmulcct.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulccb_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (plus:V4QI
       (mult:V4QI
         (match_operand:V4QI 1 "register_operand" "r")
         (vec_select:V4QI
           (match_operand:V4QI 2 "register_operand" "r")
           (parallel [(const_int 0) (const_int 0) (const_int 2) (const_int 2)])))
       (mult:V4QI
         (mult:V4QI
           (vec_select:V4QI
             (match_dup 1)
             (parallel [(const_int 1) (const_int 1) (const_int 3) (const_int 3)]))
           (match_dup 2))
         (parallel [(const_int -1) (const_int 1) (const_int -1) (const_int 1)]))))]
  "TARGET_AMETHYST"
  "pwmulccb.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulccbq_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (ss_truncate:V4QI
       (plus:V4HI
         (mult:V4HI
           (sign_extend:V4HI
             (match_operand:V4QI 1 "register_operand" "r"))
           (sign_extend:V4HI
             (vec_select:V4QI
               (match_operand:V4QI 2 "register_operand" "r")
               (parallel [(const_int 0) (const_int 0) (const_int 2) (const_int 2)]))))
         (mult:V4HI
           (mult:V4HI
             (sign_extend:V4HI
               (vec_select:V4QI
                 (match_dup 1)
                 (parallel [(const_int 1) (const_int 1) (const_int 3) (const_int 3)])))
             (sign_extend:V4HI
               (match_dup 2)))
           (parallel [(const_int -1) (const_int 1) (const_int -1) (const_int 1)])))))]
  "TARGET_AMETHYST"
  "pwmulccbq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulcct_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (truncate:V2HI
       (lshiftrt:V2SI
         (plus:V2SI
           (mult:V2SI
             (sign_extend:V2SI
               (match_operand:V2HI 1 "register_operand" "r"))
             (sign_extend:V2SI
               (vec_select:V2HI
                 (match_operand:V2HI 2 "register_operand" "r")
                 (parallel [(const_int 0) (const_int 0)]))))
           (mult:V2SI
             (mult:V2SI
               (sign_extend:V2SI
                 (vec_select:V2HI
                   (match_dup 1)
                   (parallel [(const_int 1) (const_int 1)])))
               (sign_extend:V2SI
                 (match_dup 2)))
             (parallel [(const_int -1) (const_int 1)])))
         (const_int 16))))]
  "TARGET_AMETHYST"
  "pwmulcct.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulccb_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (plus:V2HI
       (mult:V2HI
         (match_operand:V2HI 1 "register_operand" "r")
         (vec_select:V2HI
           (match_operand:V2HI 2 "register_operand" "r")
           (parallel [(const_int 0) (const_int 0)])))
       (mult:V2HI
         (mult:V2HI
           (vec_select:V2HI
             (match_dup 1)
             (parallel [(const_int 1) (const_int 1)]))
           (match_dup 2))
         (parallel [(const_int -1) (const_int 1)]))))]
  "TARGET_AMETHYST"
  "pwmulccb.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulccbq_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (plus:V2SI
         (mult:V2SI
           (sign_extend:V2SI
             (match_operand:V2HI 1 "register_operand" "r"))
           (sign_extend:V2SI
             (vec_select:V2HI
               (match_operand:V2HI 2 "register_operand" "r")
               (parallel [(const_int 0) (const_int 0)]))))
         (mult:V2SI
           (mult:V2SI
             (sign_extend:V2SI
               (vec_select:V2HI
                 (match_dup 1)
                 (parallel [(const_int 1) (const_int 1)])))
             (sign_extend:V2SI
               (match_dup 2)))
           (parallel [(const_int -1) (const_int 1)])))))]
  "TARGET_AMETHYST"
  "pwmulccbq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmulcct_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (truncate:V8QI
       (lshiftrt:V8HI
         (plus:V8HI
           (mult:V8HI
             (sign_extend:V8HI
               (match_operand:V8QI 1 "register_operand" "r"))
             (sign_extend:V8HI
               (vec_select:V8QI
                 (match_operand:V8QI 2 "register_operand" "r")
                 (parallel [(const_int 0) (const_int 0) (const_int 2) (const_int 2) (const_int 4) (const_int 4) (const_int 6) (const_int 6)]))))
           (mult:V8HI
             (mult:V8HI
               (sign_extend:V8HI
                 (vec_select:V8QI
                   (match_dup 1)
                   (parallel [(const_int 1) (const_int 1) (const_int 3) (const_int 3) (const_int 5) (const_int 5) (const_int 7) (const_int 7)])))
               (sign_extend:V8HI
                 (match_dup 2)))
             (parallel [(const_int -1) (const_int 1) (const_int -1) (const_int 1) (const_int -1) (const_int 1) (const_int -1) (const_int 1)])))
         (const_int 8))))]
  "TARGET_AMETHYST"
  "pdmulcct.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulccb_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (plus:V8QI
       (mult:V8QI
         (match_operand:V8QI 1 "register_operand" "r")
         (vec_select:V8QI
           (match_operand:V8QI 2 "register_operand" "r")
           (parallel [(const_int 0) (const_int 0) (const_int 2) (const_int 2) (const_int 4) (const_int 4) (const_int 6) (const_int 6)])))
       (mult:V8QI
         (mult:V8QI
           (vec_select:V8QI
             (match_dup 1)
             (parallel [(const_int 1) (const_int 1) (const_int 3) (const_int 3) (const_int 5) (const_int 5) (const_int 7) (const_int 7)]))
           (match_dup 2))
         (parallel [(const_int -1) (const_int 1) (const_int -1) (const_int 1) (const_int -1) (const_int 1) (const_int -1) (const_int 1)]))))]
  "TARGET_AMETHYST"
  "pdmulccb.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulccbq_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (ss_truncate:V8QI
       (plus:V8HI
         (mult:V8HI
           (sign_extend:V8HI
             (match_operand:V8QI 1 "register_operand" "r"))
           (sign_extend:V8HI
             (vec_select:V8QI
               (match_operand:V8QI 2 "register_operand" "r")
               (parallel [(const_int 0) (const_int 0) (const_int 2) (const_int 2) (const_int 4) (const_int 4) (const_int 6) (const_int 6)]))))
         (mult:V8HI
           (mult:V8HI
             (sign_extend:V8HI
               (vec_select:V8QI
                 (match_dup 1)
                 (parallel [(const_int 1) (const_int 1) (const_int 3) (const_int 3) (const_int 5) (const_int 5) (const_int 7) (const_int 7)])))
             (sign_extend:V8HI
               (match_dup 2)))
           (parallel [(const_int -1) (const_int 1) (const_int -1) (const_int 1) (const_int -1) (const_int 1) (const_int -1) (const_int 1)])))))]
  "TARGET_AMETHYST"
  "pdmulccbq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulcct_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (truncate:V4HI
       (lshiftrt:V4SI
         (plus:V4SI
           (mult:V4SI
             (sign_extend:V4SI
               (match_operand:V4HI 1 "register_operand" "r"))
             (sign_extend:V4SI
               (vec_select:V4HI
                 (match_operand:V4HI 2 "register_operand" "r")
                 (parallel [(const_int 0) (const_int 0) (const_int 2) (const_int 2)]))))
           (mult:V4SI
             (mult:V4SI
               (sign_extend:V4SI
                 (vec_select:V4HI
                   (match_dup 1)
                   (parallel [(const_int 1) (const_int 1) (const_int 3) (const_int 3)])))
               (sign_extend:V4SI
                 (match_dup 2)))
             (parallel [(const_int -1) (const_int 1) (const_int -1) (const_int 1)])))
         (const_int 16))))]
  "TARGET_AMETHYST"
  "pdmulcct.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulccb_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (plus:V4HI
       (mult:V4HI
         (match_operand:V4HI 1 "register_operand" "r")
         (vec_select:V4HI
           (match_operand:V4HI 2 "register_operand" "r")
           (parallel [(const_int 0) (const_int 0) (const_int 2) (const_int 2)])))
       (mult:V4HI
         (mult:V4HI
           (vec_select:V4HI
             (match_dup 1)
             (parallel [(const_int 1) (const_int 1) (const_int 3) (const_int 3)]))
           (match_dup 2))
         (parallel [(const_int -1) (const_int 1) (const_int -1) (const_int 1)]))))]
  "TARGET_AMETHYST"
  "pdmulccb.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulccbq_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (ss_truncate:V4HI
       (plus:V4SI
         (mult:V4SI
           (sign_extend:V4SI
             (match_operand:V4HI 1 "register_operand" "r"))
           (sign_extend:V4SI
             (vec_select:V4HI
               (match_operand:V4HI 2 "register_operand" "r")
               (parallel [(const_int 0) (const_int 0) (const_int 2) (const_int 2)]))))
         (mult:V4SI
           (mult:V4SI
             (sign_extend:V4SI
               (vec_select:V4HI
                 (match_dup 1)
                 (parallel [(const_int 1) (const_int 1) (const_int 3) (const_int 3)])))
             (sign_extend:V4SI
               (match_dup 2)))
           (parallel [(const_int -1) (const_int 1) (const_int -1) (const_int 1)])))))]
  "TARGET_AMETHYST"
  "pdmulccbq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulcct_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (truncate:V2SI
       (lshiftrt:V2DI
         (plus:V2DI
           (mult:V2DI
             (sign_extend:V2DI
               (match_operand:V2SI 1 "register_operand" "r"))
             (sign_extend:V2DI
               (vec_select:V2SI
                 (match_operand:V2SI 2 "register_operand" "r")
                 (parallel [(const_int 0) (const_int 0)]))))
           (mult:V2DI
             (mult:V2DI
               (sign_extend:V2DI
                 (vec_select:V2SI
                   (match_dup 1)
                   (parallel [(const_int 1) (const_int 1)])))
               (sign_extend:V2DI
                 (match_dup 2)))
             (parallel [(const_int -1) (const_int 1)])))
         (const_int 32))))]
  "TARGET_AMETHYST"
  "pdmulcct.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulccb_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (plus:V2SI
       (mult:V2SI
         (match_operand:V2SI 1 "register_operand" "r")
         (vec_select:V2SI
           (match_operand:V2SI 2 "register_operand" "r")
           (parallel [(const_int 0) (const_int 0)])))
       (mult:V2SI
         (mult:V2SI
           (vec_select:V2SI
             (match_dup 1)
             (parallel [(const_int 1) (const_int 1)]))
           (match_dup 2))
         (parallel [(const_int -1) (const_int 1)]))))]
  "TARGET_AMETHYST"
  "pdmulccb.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulccbq_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (plus:V2DI
         (mult:V2DI
           (sign_extend:V2DI
             (match_operand:V2SI 1 "register_operand" "r"))
           (sign_extend:V2DI
             (vec_select:V2SI
               (match_operand:V2SI 2 "register_operand" "r")
               (parallel [(const_int 0) (const_int 0)]))))
         (mult:V2DI
           (mult:V2DI
             (sign_extend:V2DI
               (vec_select:V2SI
                 (match_dup 1)
                 (parallel [(const_int 1) (const_int 1)])))
             (sign_extend:V2DI
               (match_dup 2)))
           (parallel [(const_int -1) (const_int 1)])))))]
  "TARGET_AMETHYST"
  "pdmulccbq.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmulccw_b"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (plus:V4HI
       (mult:V4HI
         (sign_extend:V4HI
           (match_operand:V4QI 1 "register_operand" "r"))
         (sign_extend:V4HI
           (vec_select:V4QI
             (match_operand:V4QI 2 "register_operand" "r")
             (parallel [(const_int 0) (const_int 0) (const_int 2) (const_int 2)]))))
       (mult:V4HI
         (mult:V4HI
           (sign_extend:V4HI
             (vec_select:V4QI
               (match_dup 1)
               (parallel [(const_int 1) (const_int 1) (const_int 3) (const_int 3)])))
           (sign_extend:V4HI
             (match_dup 2)))
         (parallel [(const_int -1) (const_int 1) (const_int -1) (const_int 1)]))))]
  "TARGET_AMETHYST"
  "pwmulccw.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmulccw_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (plus:V2SI
       (mult:V2SI
         (sign_extend:V2SI
           (match_operand:V2HI 1 "register_operand" "r"))
         (sign_extend:V2SI
           (vec_select:V2HI
             (match_operand:V2HI 2 "register_operand" "r")
             (parallel [(const_int 0) (const_int 0)]))))
       (mult:V2SI
         (mult:V2SI
           (sign_extend:V2SI
             (vec_select:V2HI
               (match_dup 1)
               (parallel [(const_int 1) (const_int 1)])))
           (sign_extend:V2SI
             (match_dup 2)))
         (parallel [(const_int -1) (const_int 1)]))))]
  "TARGET_AMETHYST"
  "pwmulccw.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmulcrt_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (truncate:V4QI
       (lshiftrt:V4HI
         (mult:V4HI
           (sign_extend:V4HI
             (match_operand:V4QI 1 "register_operand" "r"))
           (sign_extend:V4HI
             (vec_select:V4QI
               (match_operand:V2QI 2 "register_operand" "r")
               (parallel [(const_int 0) (const_int 0) (const_int 1) (const_int 1)]))))
         (const_int 8))))]
  "TARGET_AMETHYST"
  "pwmulcrt.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulcrb_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (mult:V4QI
       (match_operand:V4QI 1 "register_operand" "r")
       (vec_select:V4QI
         (match_operand:V2QI 2 "register_operand" "r")
         (parallel [(const_int 0) (const_int 0) (const_int 1) (const_int 1)]))))]
  "TARGET_AMETHYST"
  "pwmulcrb.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulcrbq_b"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
     (ss_truncate:V4QI
       (mult:V4HI
         (sign_extend:V4HI
           (match_operand:V4QI 1 "register_operand" "r"))
         (sign_extend:V4HI
           (vec_select:V4QI
             (match_operand:V2QI 2 "register_operand" "r")
             (parallel [(const_int 0) (const_int 0) (const_int 1) (const_int 1)]))))))]
  "TARGET_AMETHYST"
  "pwmulcrbq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulcrt_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (truncate:V2HI
       (lshiftrt:V2SI
         (mult:V2SI
           (sign_extend:V2SI
             (match_operand:V2HI 1 "register_operand" "r"))
           (sign_extend:V2SI
             (vec_duplicate:V2HI
               (match_operand:HI 2 "register_operand" "r"))))
         (const_int 16))))]
  "TARGET_AMETHYST"
  "pwmulcrt.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulcrb_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (mult:V2HI
       (match_operand:V2HI 1 "register_operand" "r")
       (vec_duplicate:V2HI
         (match_operand:HI 2 "register_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwmulcrb.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmulcrbq_h"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (mult:V2SI
         (sign_extend:V2SI
           (match_operand:V2HI 1 "register_operand" "r"))
         (sign_extend:V2SI
           (vec_duplicate:V2HI
             (match_operand:HI 2 "register_operand" "r"))))))]
  "TARGET_AMETHYST"
  "pwmulcrbq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmulcrt_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (truncate:V8QI
       (lshiftrt:V8HI
         (mult:V8HI
           (sign_extend:V8HI
             (match_operand:V8QI 1 "register_operand" "r"))
           (sign_extend:V8HI
             (vec_select:V8QI
               (match_operand:V4QI 2 "register_operand" "r")
               (parallel [(const_int 0) (const_int 0) (const_int 1) (const_int 1) (const_int 2) (const_int 2) (const_int 3) (const_int 3)]))))
         (const_int 8))))]
  "TARGET_AMETHYST"
  "pdmulcrt.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulcrb_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (mult:V8QI
       (match_operand:V8QI 1 "register_operand" "r")
       (vec_select:V8QI
         (match_operand:V4QI 2 "register_operand" "r")
         (parallel [(const_int 0) (const_int 0) (const_int 1) (const_int 1) (const_int 2) (const_int 2) (const_int 3) (const_int 3)]))))]
  "TARGET_AMETHYST"
  "pdmulcrb.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulcrbq_b"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
     (ss_truncate:V8QI
       (mult:V8HI
         (sign_extend:V8HI
           (match_operand:V8QI 1 "register_operand" "r"))
         (sign_extend:V8HI
           (vec_select:V8QI
             (match_operand:V4QI 2 "register_operand" "r")
             (parallel [(const_int 0) (const_int 0) (const_int 1) (const_int 1) (const_int 2) (const_int 2) (const_int 3) (const_int 3)]))))))]
  "TARGET_AMETHYST"
  "pdmulcrbq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulcrt_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (truncate:V4HI
       (lshiftrt:V4SI
         (mult:V4SI
           (sign_extend:V4SI
             (match_operand:V4HI 1 "register_operand" "r"))
           (sign_extend:V4SI
             (vec_select:V4HI
               (match_operand:V2HI 2 "register_operand" "r")
               (parallel [(const_int 0) (const_int 0) (const_int 1) (const_int 1)]))))
         (const_int 16))))]
  "TARGET_AMETHYST"
  "pdmulcrt.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulcrb_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (mult:V4HI
       (match_operand:V4HI 1 "register_operand" "r")
       (vec_select:V4HI
         (match_operand:V2HI 2 "register_operand" "r")
         (parallel [(const_int 0) (const_int 0) (const_int 1) (const_int 1)]))))]
  "TARGET_AMETHYST"
  "pdmulcrb.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulcrbq_h"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (ss_truncate:V4HI
       (mult:V4SI
         (sign_extend:V4SI
           (match_operand:V4HI 1 "register_operand" "r"))
         (sign_extend:V4SI
           (vec_select:V4HI
             (match_operand:V2HI 2 "register_operand" "r")
             (parallel [(const_int 0) (const_int 0) (const_int 1) (const_int 1)]))))))]
  "TARGET_AMETHYST"
  "pdmulcrbq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulcrt_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (truncate:V2SI
       (lshiftrt:V2DI
         (mult:V2DI
           (sign_extend:V2DI
             (match_operand:V2SI 1 "register_operand" "r"))
           (sign_extend:V2DI
             (vec_duplicate:V2SI
               (match_operand:SI 2 "register_operand" "r"))))
         (const_int 32))))]
  "TARGET_AMETHYST"
  "pdmulcrt.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulcrb_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (mult:V2SI
       (match_operand:V2SI 1 "register_operand" "r")
       (vec_duplicate:V2SI
         (match_operand:SI 2 "register_operand" "r"))))]
  "TARGET_AMETHYST"
  "pdmulcrb.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmulcrbq_w"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (mult:V2DI
         (sign_extend:V2DI
           (match_operand:V2SI 1 "register_operand" "r"))
         (sign_extend:V2DI
           (vec_duplicate:V2SI
             (match_operand:SI 2 "register_operand" "r"))))))]
  "TARGET_AMETHYST"
  "pdmulcrbq.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmulcrw_b"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
     (mult:V4HI
       (sign_extend:V4HI
         (match_operand:V4QI 1 "register_operand" "r"))
       (sign_extend:V4HI
         (vec_select:V4QI
           (match_operand:V2QI 2 "register_operand" "r")
           (parallel [(const_int 0) (const_int 0) (const_int 1) (const_int 1)])))))]
  "TARGET_AMETHYST"
  "pwmulcrw.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmulcrw_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (mult:V2SI
       (sign_extend:V2SI
         (match_operand:V2HI 1 "register_operand" "r"))
       (sign_extend:V2SI
         (vec_duplicate:V2HI
           (match_operand:HI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmulcrw.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmaccu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (plus:HI
       (match_operand:HI 3 "register_operand" "r")
       (plus:HI
         (plus:HI
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:HI
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pwmaccu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmaccs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (plus:HI
       (match_operand:HI 3 "register_operand" "r")
       (plus:HI
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pwmaccs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmaccqu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (us_truncate:HI
       (plus:SI
         (zero_extend:SI
           (match_operand:HI 3 "register_operand" "r"))
         (plus:SI
           (plus:SI
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:SI
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pwmaccqu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmaccqs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (ss_truncate:HI
       (plus:SI
         (sign_extend:SI
           (match_operand:HI 3 "register_operand" "r"))
         (plus:SI
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pwmaccqs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmaccu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (plus:HI
       (plus:HI
         (mult:HI
           (zero_extend:HI
             (vec_select:QI
               (match_operand:V4QI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (zero_extend:HI
             (vec_select:QI
               (match_operand:V4QI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:HI
           (zero_extend:HI
             (vec_select:QI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (zero_extend:HI
             (vec_select:QI
               (match_dup 2)
               (parallel [(const_int 1)])))))
       (plus:HI
         (mult:HI
           (zero_extend:HI
             (vec_select:QI
               (match_dup 1)
               (parallel [(const_int 2)])))
           (zero_extend:HI
             (vec_select:QI
               (match_dup 2)
               (parallel [(const_int 2)]))))
         (mult:HI
           (zero_extend:HI
             (vec_select:QI
               (match_dup 1)
               (parallel [(const_int 3)])))
           (zero_extend:HI
             (vec_select:QI
               (match_dup 2)
               (parallel [(const_int 3)])))))))]
  "TARGET_AMETHYST"
  "pwzmaccu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmaccs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (plus:HI
       (plus:HI
         (mult:HI
           (sign_extend:HI
             (vec_select:QI
               (match_operand:V4QI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:HI
             (vec_select:QI
               (match_operand:V4QI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:HI
           (sign_extend:HI
             (vec_select:QI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (sign_extend:HI
             (vec_select:QI
               (match_dup 2)
               (parallel [(const_int 1)])))))
       (plus:HI
         (mult:HI
           (sign_extend:HI
             (vec_select:QI
               (match_dup 1)
               (parallel [(const_int 2)])))
           (sign_extend:HI
             (vec_select:QI
               (match_dup 2)
               (parallel [(const_int 2)]))))
         (mult:HI
           (sign_extend:HI
             (vec_select:QI
               (match_dup 1)
               (parallel [(const_int 3)])))
           (sign_extend:HI
             (vec_select:QI
               (match_dup 2)
               (parallel [(const_int 3)])))))))]
  "TARGET_AMETHYST"
  "pwzmaccs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmaccqu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (us_truncate:HI
       (plus:SI
         (plus:SI
           (mult:SI
             (zero_extend:SI
               (vec_select:QI
                 (match_operand:V4QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (zero_extend:SI
               (vec_select:QI
                 (match_operand:V4QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (zero_extend:SI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (zero_extend:SI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:SI
           (mult:SI
             (zero_extend:SI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (zero_extend:SI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:SI
             (zero_extend:SI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (zero_extend:SI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pwzmaccqu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmaccqs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (ss_truncate:HI
       (plus:SI
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:QI
                 (match_operand:V4QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:QI
                 (match_operand:V4QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:SI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:SI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (sign_extend:SI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pwzmaccqs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmsubu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (minus:HI
       (match_operand:HI 3 "register_operand" "r")
       (plus:HI
         (plus:HI
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:HI
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pwmsubu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmsubs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (minus:HI
       (match_operand:HI 3 "register_operand" "r")
       (plus:HI
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pwmsubs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmsubqu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (us_truncate:HI
       (minus:SI
         (zero_extend:SI
           (match_operand:HI 3 "register_operand" "r"))
         (plus:SI
           (plus:SI
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:SI
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pwmsubqu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmsubqs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (ss_truncate:HI
       (minus:SI
         (sign_extend:SI
           (match_operand:HI 3 "register_operand" "r"))
         (plus:SI
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pwmsubqs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmsubu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (neg:HI
       (plus:HI
         (plus:HI
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:HI
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pwzmsubu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmsubs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (neg:HI
       (plus:HI
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pwzmsubs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmsubqu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (us_truncate:HI
       (neg:SI
         (plus:SI
           (plus:SI
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:SI
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pwzmsubqu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmsubqs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (ss_truncate:HI
       (neg:SI
         (plus:SI
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pwzmsubqs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmaccu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (plus:SI
       (match_operand:SI 3 "register_operand" "r")
       (plus:SI
         (mult:SI
           (zero_extend:SI
             (vec_select:HI
               (match_operand:V2HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (zero_extend:SI
             (vec_select:HI
               (match_operand:V2HI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:SI
           (zero_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (zero_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pwmaccu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmaccs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (plus:SI
       (match_operand:SI 3 "register_operand" "r")
       (plus:SI
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_operand:V2HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:SI
             (vec_select:HI
               (match_operand:V2HI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (sign_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pwmaccs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmaccqu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (us_truncate:SI
       (plus:DI
         (zero_extend:DI
           (match_operand:SI 3 "register_operand" "r"))
         (plus:DI
           (mult:DI
             (zero_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (zero_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:DI
             (zero_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (zero_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pwmaccqu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmaccqs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ss_truncate:SI
       (plus:DI
         (sign_extend:DI
           (match_operand:SI 3 "register_operand" "r"))
         (plus:DI
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pwmaccqs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmaccu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (plus:SI
       (mult:SI
         (zero_extend:SI
           (vec_select:HI
             (match_operand:V2HI 1 "register_operand" "r")
             (parallel [(const_int 0)])))
         (zero_extend:SI
           (vec_select:HI
             (match_operand:V2HI 2 "register_operand" "r")
             (parallel [(const_int 0)]))))
       (mult:SI
         (zero_extend:SI
           (vec_select:HI
             (match_dup 1)
             (parallel [(const_int 1)])))
         (zero_extend:SI
           (vec_select:HI
             (match_dup 2)
             (parallel [(const_int 1)]))))))]
  "TARGET_AMETHYST"
  "pwzmaccu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmaccs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (plus:SI
       (mult:SI
         (sign_extend:SI
           (vec_select:HI
             (match_operand:V2HI 1 "register_operand" "r")
             (parallel [(const_int 0)])))
         (sign_extend:SI
           (vec_select:HI
             (match_operand:V2HI 2 "register_operand" "r")
             (parallel [(const_int 0)]))))
       (mult:SI
         (sign_extend:SI
           (vec_select:HI
             (match_dup 1)
             (parallel [(const_int 1)])))
         (sign_extend:SI
           (vec_select:HI
             (match_dup 2)
             (parallel [(const_int 1)]))))))]
  "TARGET_AMETHYST"
  "pwzmaccs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmaccqu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (us_truncate:SI
       (plus:DI
         (mult:DI
           (zero_extend:DI
             (vec_select:HI
               (match_operand:V2HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (zero_extend:DI
             (vec_select:HI
               (match_operand:V2HI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:DI
           (zero_extend:DI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (zero_extend:DI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pwzmaccqu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmaccqs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ss_truncate:SI
       (plus:DI
         (mult:DI
           (sign_extend:DI
             (vec_select:HI
               (match_operand:V2HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:DI
             (vec_select:HI
               (match_operand:V2HI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:DI
           (sign_extend:DI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (sign_extend:DI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pwzmaccqs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmsubu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (minus:SI
       (match_operand:SI 3 "register_operand" "r")
       (plus:SI
         (mult:SI
           (zero_extend:SI
             (vec_select:HI
               (match_operand:V2HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (zero_extend:SI
             (vec_select:HI
               (match_operand:V2HI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:SI
           (zero_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (zero_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pwmsubu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmsubs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (minus:SI
       (match_operand:SI 3 "register_operand" "r")
       (plus:SI
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_operand:V2HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:SI
             (vec_select:HI
               (match_operand:V2HI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (sign_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pwmsubs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmsubqu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (us_truncate:SI
       (minus:DI
         (zero_extend:DI
           (match_operand:SI 3 "register_operand" "r"))
         (plus:DI
           (mult:DI
             (zero_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (zero_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:DI
             (zero_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (zero_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pwmsubqu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmsubqs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ss_truncate:SI
       (minus:DI
         (sign_extend:DI
           (match_operand:SI 3 "register_operand" "r"))
         (plus:DI
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pwmsubqs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmsubu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (neg:SI
       (plus:SI
         (mult:SI
           (zero_extend:SI
             (vec_select:HI
               (match_operand:V2HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (zero_extend:SI
             (vec_select:HI
               (match_operand:V2HI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:SI
           (zero_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (zero_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pwzmsubu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmsubs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (neg:SI
       (plus:SI
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_operand:V2HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:SI
             (vec_select:HI
               (match_operand:V2HI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (sign_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pwzmsubs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmsubqu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (us_truncate:SI
       (neg:DI
         (plus:DI
           (mult:DI
             (zero_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (zero_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:DI
             (zero_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (zero_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pwzmsubqu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmsubqs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ss_truncate:SI
       (neg:DI
         (plus:DI
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pwzmsubqs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmaccu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (plus:DI
       (match_operand:DI 3 "register_operand" "r")
       (mult:DI
         (zero_extend:DI
           (match_operand:SI 1 "register_operand" "r"))
         (zero_extend:DI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmaccu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmaccs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (plus:DI
       (match_operand:DI 3 "register_operand" "r")
       (mult:DI
         (sign_extend:DI
           (match_operand:SI 1 "register_operand" "r"))
         (sign_extend:DI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmaccs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmaccqu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (us_truncate:DI
       (plus:TI
         (zero_extend:TI
           (match_operand:DI 3 "register_operand" "r"))
         (mult:TI
           (zero_extend:TI
             (match_operand:SI 1 "register_operand" "r"))
           (zero_extend:TI
             (match_operand:SI 2 "register_operand" "r"))))))]
  "TARGET_AMETHYST"
  "pwmaccqu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmaccqs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (ss_truncate:DI
       (plus:TI
         (sign_extend:TI
           (match_operand:DI 3 "register_operand" "r"))
         (mult:TI
           (sign_extend:TI
             (match_operand:SI 1 "register_operand" "r"))
           (sign_extend:TI
             (match_operand:SI 2 "register_operand" "r"))))))]
  "TARGET_AMETHYST"
  "pwmaccqs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmaccu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (mult:DI
       (zero_extend:DI
         (match_operand:SI 1 "register_operand" "r"))
       (zero_extend:DI
         (match_operand:SI 2 "register_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwzmaccu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmaccs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (mult:DI
       (sign_extend:DI
         (match_operand:SI 1 "register_operand" "r"))
       (sign_extend:DI
         (match_operand:SI 2 "register_operand" "r"))))]
  "TARGET_AMETHYST"
  "pwzmaccs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmaccqu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (us_truncate:DI
       (mult:TI
         (zero_extend:TI
           (match_operand:SI 1 "register_operand" "r"))
         (zero_extend:TI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwzmaccqu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmaccqs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (ss_truncate:DI
       (mult:TI
         (sign_extend:TI
           (match_operand:SI 1 "register_operand" "r"))
         (sign_extend:TI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwzmaccqs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmsubu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (minus:DI
       (match_operand:DI 3 "register_operand" "r")
       (mult:DI
         (zero_extend:DI
           (match_operand:SI 1 "register_operand" "r"))
         (zero_extend:DI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmsubu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmsubs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (minus:DI
       (match_operand:DI 3 "register_operand" "r")
       (mult:DI
         (sign_extend:DI
           (match_operand:SI 1 "register_operand" "r"))
         (sign_extend:DI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwmsubs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmsubqu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (us_truncate:DI
       (minus:TI
         (zero_extend:TI
           (match_operand:DI 3 "register_operand" "r"))
         (mult:TI
           (zero_extend:TI
             (match_operand:SI 1 "register_operand" "r"))
           (zero_extend:TI
             (match_operand:SI 2 "register_operand" "r"))))))]
  "TARGET_AMETHYST"
  "pwmsubqu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmsubqs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (ss_truncate:DI
       (minus:TI
         (sign_extend:TI
           (match_operand:DI 3 "register_operand" "r"))
         (mult:TI
           (sign_extend:TI
             (match_operand:SI 1 "register_operand" "r"))
           (sign_extend:TI
             (match_operand:SI 2 "register_operand" "r"))))))]
  "TARGET_AMETHYST"
  "pwmsubqs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmsubu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (neg:DI
       (mult:DI
         (zero_extend:DI
           (match_operand:SI 1 "register_operand" "r"))
         (zero_extend:DI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwzmsubu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmsubs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (neg:DI
       (mult:DI
         (sign_extend:DI
           (match_operand:SI 1 "register_operand" "r"))
         (sign_extend:DI
           (match_operand:SI 2 "register_operand" "r")))))]
  "TARGET_AMETHYST"
  "pwzmsubs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmsubqu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (us_truncate:DI
       (neg:TI
         (mult:TI
           (zero_extend:TI
             (match_operand:SI 1 "register_operand" "r"))
           (zero_extend:TI
             (match_operand:SI 2 "register_operand" "r"))))))]
  "TARGET_AMETHYST"
  "pwzmsubqu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmsubqs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (ss_truncate:DI
       (neg:TI
         (mult:TI
           (sign_extend:TI
             (match_operand:SI 1 "register_operand" "r"))
           (sign_extend:TI
             (match_operand:SI 2 "register_operand" "r"))))))]
  "TARGET_AMETHYST"
  "pwzmsubqs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmaccu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (plus:HI
       (match_operand:HI 3 "register_operand" "r")
       (plus:HI
         (plus:HI
           (plus:HI
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:HI
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:HI
           (plus:HI
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 4)]))))
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 5)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 5)])))))
           (plus:HI
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 6)]))))
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 7)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 7)])))))))))]
  "TARGET_AMETHYST"
  "pdmaccu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmaccs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (plus:HI
       (match_operand:HI 3 "register_operand" "r")
       (plus:HI
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 4)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 5)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 5)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 6)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 7)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 7)])))))))))]
  "TARGET_AMETHYST"
  "pdmaccs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmaccqu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (us_truncate:HI
       (plus:SI
         (zero_extend:SI
           (match_operand:HI 3 "register_operand" "r"))
         (plus:SI
           (plus:SI
             (plus:SI
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (plus:SI
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:SI
             (plus:SI
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 4)]))))
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 5)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 5)])))))
             (plus:SI
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 6)]))))
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 7)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 7)]))))))))))]
  "TARGET_AMETHYST"
  "pdmaccqu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmaccqs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (ss_truncate:HI
       (plus:SI
         (sign_extend:SI
           (match_operand:HI 3 "register_operand" "r"))
         (plus:SI
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 4)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 5)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 5)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 6)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 7)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 7)]))))))))))]
  "TARGET_AMETHYST"
  "pdmaccqs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmaccu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (plus:HI
       (plus:HI
         (plus:HI
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_operand:V8QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_operand:V8QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:HI
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))
       (plus:HI
         (plus:HI
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 4)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 4)]))))
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 5)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 5)])))))
         (plus:HI
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 6)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 6)]))))
           (mult:HI
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 7)])))
             (zero_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 7)]))))))))]
  "TARGET_AMETHYST"
  "pdzmaccu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmaccs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (plus:HI
       (plus:HI
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V8QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V8QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))
       (plus:HI
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 4)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 4)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 5)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 5)])))))
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 6)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 6)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 7)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 7)]))))))))]
  "TARGET_AMETHYST"
  "pdzmaccs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmaccqu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (us_truncate:HI
       (plus:SI
         (plus:SI
           (plus:SI
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_operand:V8QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_operand:V8QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:SI
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:SI
           (plus:SI
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 4)]))))
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 5)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 5)])))))
           (plus:SI
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 6)]))))
             (mult:SI
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 7)])))
               (zero_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 7)])))))))))]
  "TARGET_AMETHYST"
  "pdzmaccqu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmaccqs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (ss_truncate:HI
       (plus:SI
         (plus:SI
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V8QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V8QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:SI
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 4)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 5)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 5)])))))
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 6)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 7)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 7)])))))))))]
  "TARGET_AMETHYST"
  "pdzmaccqs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmsubu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (minus:HI
       (match_operand:HI 3 "register_operand" "r")
       (plus:HI
         (plus:HI
           (plus:HI
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:HI
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:HI
           (plus:HI
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 4)]))))
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 5)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 5)])))))
           (plus:HI
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 6)]))))
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 7)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 7)])))))))))]
  "TARGET_AMETHYST"
  "pdmsubu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmsubs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (minus:HI
       (match_operand:HI 3 "register_operand" "r")
       (plus:HI
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 4)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 5)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 5)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 6)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 7)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 7)])))))))))]
  "TARGET_AMETHYST"
  "pdmsubs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmsubqu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (us_truncate:HI
       (minus:SI
         (zero_extend:SI
           (match_operand:HI 3 "register_operand" "r"))
         (plus:SI
           (plus:SI
             (plus:SI
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (plus:SI
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:SI
             (plus:SI
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 4)]))))
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 5)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 5)])))))
             (plus:SI
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 6)]))))
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 7)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 7)]))))))))))]
  "TARGET_AMETHYST"
  "pdmsubqu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmsubqs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (ss_truncate:HI
       (minus:SI
         (sign_extend:SI
           (match_operand:HI 3 "register_operand" "r"))
         (plus:SI
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 4)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 5)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 5)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 6)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 7)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 7)]))))))))))]
  "TARGET_AMETHYST"
  "pdmsubqs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmsubu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (neg:HI
       (plus:HI
         (plus:HI
           (plus:HI
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:HI
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:HI
           (plus:HI
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 4)]))))
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 5)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 5)])))))
           (plus:HI
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 6)]))))
             (mult:HI
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 7)])))
               (zero_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 7)])))))))))]
  "TARGET_AMETHYST"
  "pdzmsubu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmsubs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (neg:HI
       (plus:HI
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 4)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 5)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 5)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 6)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 7)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 7)])))))))))]
  "TARGET_AMETHYST"
  "pdzmsubs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmsubqu_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (us_truncate:HI
       (neg:SI
         (plus:SI
           (plus:SI
             (plus:SI
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (plus:SI
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:SI
             (plus:SI
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 4)]))))
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 5)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 5)])))))
             (plus:SI
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 6)]))))
               (mult:SI
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 7)])))
                 (zero_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 7)]))))))))))]
  "TARGET_AMETHYST"
  "pdzmsubqu.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmsubqs_b"
  [(set (match_operand:HI 0 "register_operand" "=r")
     (ss_truncate:HI
       (neg:SI
         (plus:SI
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 4)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 5)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 5)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 6)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 7)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 7)]))))))))))]
  "TARGET_AMETHYST"
  "pdzmsubqs.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmaccu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (plus:SI
       (match_operand:SI 3 "register_operand" "r")
       (plus:SI
         (plus:SI
           (mult:SI
             (zero_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (zero_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:SI
           (mult:SI
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:SI
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pdmaccu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmaccs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (plus:SI
       (match_operand:SI 3 "register_operand" "r")
       (plus:SI
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pdmaccs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmaccqu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (us_truncate:SI
       (plus:DI
         (zero_extend:DI
           (match_operand:SI 3 "register_operand" "r"))
         (plus:DI
           (plus:DI
             (mult:DI
               (zero_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (zero_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:DI
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:DI
             (mult:DI
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:DI
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pdmaccqu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmaccqs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ss_truncate:SI
       (plus:DI
         (sign_extend:DI
           (match_operand:SI 3 "register_operand" "r"))
         (plus:DI
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pdmaccqs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmaccu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (plus:SI
       (plus:SI
         (mult:SI
           (zero_extend:SI
             (vec_select:HI
               (match_operand:V4HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (zero_extend:SI
             (vec_select:HI
               (match_operand:V4HI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:SI
           (zero_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (zero_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 1)])))))
       (plus:SI
         (mult:SI
           (zero_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 2)])))
           (zero_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 2)]))))
         (mult:SI
           (zero_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 3)])))
           (zero_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 3)])))))))]
  "TARGET_AMETHYST"
  "pdzmaccu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmaccs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (plus:SI
       (plus:SI
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_operand:V4HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:SI
             (vec_select:HI
               (match_operand:V4HI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (sign_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 1)])))))
       (plus:SI
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 2)])))
           (sign_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 2)]))))
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 3)])))
           (sign_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 3)])))))))]
  "TARGET_AMETHYST"
  "pdzmaccs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmaccqu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (us_truncate:SI
       (plus:DI
         (plus:DI
           (mult:DI
             (zero_extend:DI
               (vec_select:HI
                 (match_operand:V4HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (zero_extend:DI
               (vec_select:HI
                 (match_operand:V4HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:DI
             (zero_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (zero_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:DI
           (mult:DI
             (zero_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (zero_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:DI
             (zero_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (zero_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pdzmaccqu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmaccqs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ss_truncate:SI
       (plus:DI
         (plus:DI
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_operand:V4HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_operand:V4HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:DI
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pdzmaccqs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmsubu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (minus:SI
       (match_operand:SI 3 "register_operand" "r")
       (plus:SI
         (plus:SI
           (mult:SI
             (zero_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (zero_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:SI
           (mult:SI
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:SI
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pdmsubu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmsubs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (minus:SI
       (match_operand:SI 3 "register_operand" "r")
       (plus:SI
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pdmsubs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmsubqu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (us_truncate:SI
       (minus:DI
         (zero_extend:DI
           (match_operand:SI 3 "register_operand" "r"))
         (plus:DI
           (plus:DI
             (mult:DI
               (zero_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (zero_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:DI
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:DI
             (mult:DI
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:DI
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pdmsubqu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmsubqs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ss_truncate:SI
       (minus:DI
         (sign_extend:DI
           (match_operand:SI 3 "register_operand" "r"))
         (plus:DI
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pdmsubqs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmsubu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (neg:SI
       (plus:SI
         (plus:SI
           (mult:SI
             (zero_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (zero_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:SI
           (mult:SI
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:SI
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (zero_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pdzmsubu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmsubs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (neg:SI
       (plus:SI
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pdzmsubs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmsubqu_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (us_truncate:SI
       (neg:DI
         (plus:DI
           (plus:DI
             (mult:DI
               (zero_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (zero_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:DI
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:DI
             (mult:DI
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:DI
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (zero_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pdzmsubqu.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmsubqs_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ss_truncate:SI
       (neg:DI
         (plus:DI
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pdzmsubqs.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmaccu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (plus:DI
       (match_operand:DI 3 "register_operand" "r")
       (plus:DI
         (mult:DI
           (zero_extend:DI
             (vec_select:SI
               (match_operand:V2SI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (zero_extend:DI
             (vec_select:SI
               (match_operand:V2SI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:DI
           (zero_extend:DI
             (vec_select:SI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (zero_extend:DI
             (vec_select:SI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pdmaccu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmaccs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (plus:DI
       (match_operand:DI 3 "register_operand" "r")
       (plus:DI
         (mult:DI
           (sign_extend:DI
             (vec_select:SI
               (match_operand:V2SI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:DI
             (vec_select:SI
               (match_operand:V2SI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:DI
           (sign_extend:DI
             (vec_select:SI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (sign_extend:DI
             (vec_select:SI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pdmaccs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmaccqu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (us_truncate:DI
       (plus:TI
         (zero_extend:TI
           (match_operand:DI 3 "register_operand" "r"))
         (plus:TI
           (mult:TI
             (zero_extend:TI
               (vec_select:SI
                 (match_operand:V2SI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (zero_extend:TI
               (vec_select:SI
                 (match_operand:V2SI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:TI
             (zero_extend:TI
               (vec_select:SI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (zero_extend:TI
               (vec_select:SI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pdmaccqu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmaccqs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (ss_truncate:DI
       (plus:TI
         (sign_extend:TI
           (match_operand:DI 3 "register_operand" "r"))
         (plus:TI
           (mult:TI
             (sign_extend:TI
               (vec_select:SI
                 (match_operand:V2SI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:TI
               (vec_select:SI
                 (match_operand:V2SI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:TI
             (sign_extend:TI
               (vec_select:SI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:TI
               (vec_select:SI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pdmaccqs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmaccu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (plus:DI
       (mult:DI
         (zero_extend:DI
           (vec_select:SI
             (match_operand:V2SI 1 "register_operand" "r")
             (parallel [(const_int 0)])))
         (zero_extend:DI
           (vec_select:SI
             (match_operand:V2SI 2 "register_operand" "r")
             (parallel [(const_int 0)]))))
       (mult:DI
         (zero_extend:DI
           (vec_select:SI
             (match_dup 1)
             (parallel [(const_int 1)])))
         (zero_extend:DI
           (vec_select:SI
             (match_dup 2)
             (parallel [(const_int 1)]))))))]
  "TARGET_AMETHYST"
  "pdzmaccu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmaccs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (plus:DI
       (mult:DI
         (sign_extend:DI
           (vec_select:SI
             (match_operand:V2SI 1 "register_operand" "r")
             (parallel [(const_int 0)])))
         (sign_extend:DI
           (vec_select:SI
             (match_operand:V2SI 2 "register_operand" "r")
             (parallel [(const_int 0)]))))
       (mult:DI
         (sign_extend:DI
           (vec_select:SI
             (match_dup 1)
             (parallel [(const_int 1)])))
         (sign_extend:DI
           (vec_select:SI
             (match_dup 2)
             (parallel [(const_int 1)]))))))]
  "TARGET_AMETHYST"
  "pdzmaccs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmaccqu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (us_truncate:DI
       (plus:TI
         (mult:TI
           (zero_extend:TI
             (vec_select:SI
               (match_operand:V2SI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (zero_extend:TI
             (vec_select:SI
               (match_operand:V2SI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:TI
           (zero_extend:TI
             (vec_select:SI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (zero_extend:TI
             (vec_select:SI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pdzmaccqu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmaccqs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (ss_truncate:DI
       (plus:TI
         (mult:TI
           (sign_extend:TI
             (vec_select:SI
               (match_operand:V2SI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:TI
             (vec_select:SI
               (match_operand:V2SI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:TI
           (sign_extend:TI
             (vec_select:SI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (sign_extend:TI
             (vec_select:SI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pdzmaccqs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmsubu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (minus:DI
       (match_operand:DI 3 "register_operand" "r")
       (plus:DI
         (mult:DI
           (zero_extend:DI
             (vec_select:SI
               (match_operand:V2SI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (zero_extend:DI
             (vec_select:SI
               (match_operand:V2SI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:DI
           (zero_extend:DI
             (vec_select:SI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (zero_extend:DI
             (vec_select:SI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pdmsubu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmsubs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (minus:DI
       (match_operand:DI 3 "register_operand" "r")
       (plus:DI
         (mult:DI
           (sign_extend:DI
             (vec_select:SI
               (match_operand:V2SI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:DI
             (vec_select:SI
               (match_operand:V2SI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:DI
           (sign_extend:DI
             (vec_select:SI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (sign_extend:DI
             (vec_select:SI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pdmsubs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmsubqu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (us_truncate:DI
       (minus:TI
         (zero_extend:TI
           (match_operand:DI 3 "register_operand" "r"))
         (plus:TI
           (mult:TI
             (zero_extend:TI
               (vec_select:SI
                 (match_operand:V2SI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (zero_extend:TI
               (vec_select:SI
                 (match_operand:V2SI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:TI
             (zero_extend:TI
               (vec_select:SI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (zero_extend:TI
               (vec_select:SI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pdmsubqu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmsubqs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (ss_truncate:DI
       (minus:TI
         (sign_extend:TI
           (match_operand:DI 3 "register_operand" "r"))
         (plus:TI
           (mult:TI
             (sign_extend:TI
               (vec_select:SI
                 (match_operand:V2SI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:TI
               (vec_select:SI
                 (match_operand:V2SI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:TI
             (sign_extend:TI
               (vec_select:SI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:TI
               (vec_select:SI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pdmsubqs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmsubu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (neg:DI
       (plus:DI
         (mult:DI
           (zero_extend:DI
             (vec_select:SI
               (match_operand:V2SI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (zero_extend:DI
             (vec_select:SI
               (match_operand:V2SI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:DI
           (zero_extend:DI
             (vec_select:SI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (zero_extend:DI
             (vec_select:SI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pdzmsubu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmsubs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (neg:DI
       (plus:DI
         (mult:DI
           (sign_extend:DI
             (vec_select:SI
               (match_operand:V2SI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:DI
             (vec_select:SI
               (match_operand:V2SI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:DI
           (sign_extend:DI
             (vec_select:SI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (sign_extend:DI
             (vec_select:SI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pdzmsubs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmsubqu_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (us_truncate:DI
       (neg:TI
         (plus:TI
           (mult:TI
             (zero_extend:TI
               (vec_select:SI
                 (match_operand:V2SI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (zero_extend:TI
               (vec_select:SI
                 (match_operand:V2SI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:TI
             (zero_extend:TI
               (vec_select:SI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (zero_extend:TI
               (vec_select:SI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pdzmsubqu.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmsubqs_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (ss_truncate:DI
       (neg:TI
         (plus:TI
           (mult:TI
             (sign_extend:TI
               (vec_select:SI
                 (match_operand:V2SI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:TI
               (vec_select:SI
                 (match_operand:V2SI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:TI
             (sign_extend:TI
               (vec_select:SI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:TI
               (vec_select:SI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pdzmsubqs.w\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmacccc_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (plus:V2HI
       (match_operand:V2HI 3 "register_operand" "r")
       (vec_concat:V2HI
         (plus:HI
           (minus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V4QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V4QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (minus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 0)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)])))))))))]
  "TARGET_AMETHYST"
  "pwmacccc.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmaccccq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (plus:V2SI
         (sign_extend:V2SI
           (match_operand:V2HI 3 "register_operand" "r"))
         (vec_concat:V2SI
           (plus:SI
             (minus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V4QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V4QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (minus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 0)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))))))))]
  "TARGET_AMETHYST"
  "pwmaccccq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmacccc_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (vec_concat:V2HI
       (plus:HI
         (minus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (minus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))
       (plus:HI
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 0)])))))
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))))))]
  "TARGET_AMETHYST"
  "pwzmacccc.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmaccccq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (vec_concat:V2SI
         (plus:SI
           (minus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (minus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:SI
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 0)])))))
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)])))))))))]
  "TARGET_AMETHYST"
  "pwzmaccccq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmsubcc_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (minus:V2HI
       (match_operand:V2HI 3 "register_operand" "r")
       (vec_concat:V2HI
         (plus:HI
           (minus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V4QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V4QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (minus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 0)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)])))))))))]
  "TARGET_AMETHYST"
  "pwmsubcc.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmsubccq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (minus:V2SI
         (sign_extend:V2SI
           (match_operand:V2HI 3 "register_operand" "r"))
         (vec_concat:V2SI
           (plus:SI
             (minus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V4QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V4QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (minus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 0)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))))))))]
  "TARGET_AMETHYST"
  "pwmsubccq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmsubcc_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (neg:V2HI
       (vec_concat:V2HI
         (plus:HI
           (minus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V4QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V4QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (minus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 0)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)])))))))))]
  "TARGET_AMETHYST"
  "pwzmsubcc.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmsubccq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (neg:V2SI
         (vec_concat:V2SI
           (plus:SI
             (minus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V4QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V4QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (minus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 0)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))))))))]
  "TARGET_AMETHYST"
  "pwzmsubccq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmacccc_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (plus:V2SI
       (match_operand:V2SI 3 "register_operand" "r")
       (vec_concat:V2SI
         (minus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V2HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V2HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 0)]))))))))]
  "TARGET_AMETHYST"
  "pwmacccc.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmaccccq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (plus:V2DI
         (sign_extend:V2DI
           (match_operand:V2SI 3 "register_operand" "r"))
         (vec_concat:V2DI
           (minus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V2HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V2HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 0)])))))))))]
  "TARGET_AMETHYST"
  "pwmaccccq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmacccc_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (vec_concat:V2SI
       (minus:SI
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_operand:V2HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:SI
             (vec_select:HI
               (match_operand:V2HI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (sign_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 1)])))))
       (plus:SI
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 0)])))
           (sign_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 1)]))))
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 1)])))
           (sign_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 0)])))))))]
  "TARGET_AMETHYST"
  "pwzmacccc.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmaccccq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (vec_concat:V2DI
         (minus:DI
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:DI
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 0)]))))))))]
  "TARGET_AMETHYST"
  "pwzmaccccq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmsubcc_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (minus:V2SI
       (match_operand:V2SI 3 "register_operand" "r")
       (vec_concat:V2SI
         (minus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V2HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V2HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 0)]))))))))]
  "TARGET_AMETHYST"
  "pwmsubcc.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmsubccq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (minus:V2DI
         (sign_extend:V2DI
           (match_operand:V2SI 3 "register_operand" "r"))
         (vec_concat:V2DI
           (minus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V2HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V2HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 0)])))))))))]
  "TARGET_AMETHYST"
  "pwmsubccq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmsubcc_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (neg:V2SI
       (vec_concat:V2SI
         (minus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V2HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V2HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 0)]))))))))]
  "TARGET_AMETHYST"
  "pwzmsubcc.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmsubccq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (neg:V2DI
         (vec_concat:V2DI
           (minus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V2HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V2HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 0)])))))))))]
  "TARGET_AMETHYST"
  "pwzmsubccq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmacccc_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (plus:V2HI
       (match_operand:V2HI 3 "register_operand" "r")
       (vec_concat:V2HI
         (plus:HI
           (plus:HI
             (minus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_operand:V8QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_operand:V8QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (minus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:HI
             (minus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 4)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 5)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 5)])))))
             (minus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 6)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 7)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 7)])))))))
         (plus:HI
           (plus:HI
             (plus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 0)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 0)])))))
             (plus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))))
           (plus:HI
             (plus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 5)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 5)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 4)])))))
             (plus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 7)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 7)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 6)]))))))))))]
  "TARGET_AMETHYST"
  "pdmacccc.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmaccccq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (plus:V2SI
         (sign_extend:V2SI
           (match_operand:V2HI 3 "register_operand" "r"))
         (vec_concat:V2SI
           (plus:SI
             (plus:SI
               (minus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_operand:V8QI 1 "register_operand" "r")
                       (parallel [(const_int 0)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_operand:V8QI 2 "register_operand" "r")
                       (parallel [(const_int 0)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 1)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 1)])))))
               (minus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 2)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 2)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 3)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 3)]))))))
             (plus:SI
               (minus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 4)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 4)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 5)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 5)])))))
               (minus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 6)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 6)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 7)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 7)])))))))
           (plus:SI
             (plus:SI
               (plus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 0)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 1)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 1)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 0)])))))
               (plus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 2)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 3)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 3)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 2)]))))))
             (plus:SI
               (plus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 4)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 5)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 5)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 4)])))))
               (plus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 6)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 7)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 7)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 6)])))))))))))]
  "TARGET_AMETHYST"
  "pdmaccccq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmacccc_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (vec_concat:V2HI
       (plus:HI
         (plus:HI
           (minus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (minus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:HI
           (minus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 4)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 5)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 5)])))))
           (minus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 6)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 7)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 7)])))))))
       (plus:HI
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 0)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))))
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 5)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 5)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 4)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 7)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 7)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 6)])))))))))]
  "TARGET_AMETHYST"
  "pdzmacccc.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmaccccq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (vec_concat:V2SI
         (plus:SI
           (plus:SI
             (minus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (minus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:SI
             (minus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 4)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 5)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 5)])))))
             (minus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 6)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 7)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 7)])))))))
         (plus:SI
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 0)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))))
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 5)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 5)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 4)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 7)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 7)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 6)]))))))))))]
  "TARGET_AMETHYST"
  "pdzmaccccq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmsubcc_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (minus:V2HI
       (match_operand:V2HI 3 "register_operand" "r")
       (vec_concat:V2HI
         (plus:HI
           (plus:HI
             (minus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_operand:V8QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_operand:V8QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (minus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:HI
             (minus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 4)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 5)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 5)])))))
             (minus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 6)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 7)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 7)])))))))
         (plus:HI
           (plus:HI
             (plus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 0)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 0)])))))
             (plus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))))
           (plus:HI
             (plus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 5)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 5)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 4)])))))
             (plus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 7)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 7)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 6)]))))))))))]
  "TARGET_AMETHYST"
  "pdmsubcc.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmsubccq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (minus:V2SI
         (sign_extend:V2SI
           (match_operand:V2HI 3 "register_operand" "r"))
         (vec_concat:V2SI
           (plus:SI
             (plus:SI
               (minus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_operand:V8QI 1 "register_operand" "r")
                       (parallel [(const_int 0)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_operand:V8QI 2 "register_operand" "r")
                       (parallel [(const_int 0)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 1)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 1)])))))
               (minus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 2)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 2)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 3)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 3)]))))))
             (plus:SI
               (minus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 4)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 4)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 5)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 5)])))))
               (minus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 6)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 6)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 7)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 7)])))))))
           (plus:SI
             (plus:SI
               (plus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 0)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 1)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 1)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 0)])))))
               (plus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 2)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 3)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 3)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 2)]))))))
             (plus:SI
               (plus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 4)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 5)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 5)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 4)])))))
               (plus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 6)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 7)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 7)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 6)])))))))))))]
  "TARGET_AMETHYST"
  "pdmsubccq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmsubcc_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (neg:V2HI
       (vec_concat:V2HI
         (plus:HI
           (plus:HI
             (minus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_operand:V8QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_operand:V8QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (minus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:HI
             (minus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 4)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 5)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 5)])))))
             (minus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 6)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 7)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 7)])))))))
         (plus:HI
           (plus:HI
             (plus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 0)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 0)])))))
             (plus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))))
           (plus:HI
             (plus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 5)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 5)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 4)])))))
             (plus:HI
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 7)]))))
               (mult:HI
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 7)])))
                 (sign_extend:HI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 6)]))))))))))]
  "TARGET_AMETHYST"
  "pdzmsubcc.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmsubccq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (neg:V2SI
         (vec_concat:V2SI
           (plus:SI
             (plus:SI
               (minus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_operand:V8QI 1 "register_operand" "r")
                       (parallel [(const_int 0)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_operand:V8QI 2 "register_operand" "r")
                       (parallel [(const_int 0)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 1)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 1)])))))
               (minus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 2)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 2)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 3)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 3)]))))))
             (plus:SI
               (minus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 4)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 4)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 5)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 5)])))))
               (minus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 6)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 6)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 7)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 7)])))))))
           (plus:SI
             (plus:SI
               (plus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 0)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 1)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 1)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 0)])))))
               (plus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 2)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 3)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 3)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 2)]))))))
             (plus:SI
               (plus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 4)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 5)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 5)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 4)])))))
               (plus:SI
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 6)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 7)]))))
                 (mult:SI
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 1)
                       (parallel [(const_int 7)])))
                   (sign_extend:SI
                     (vec_select:QI
                       (match_dup 2)
                       (parallel [(const_int 6)])))))))))))]
  "TARGET_AMETHYST"
  "pdzmsubccq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmacccc_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (plus:V2SI
       (match_operand:V2SI 3 "register_operand" "r")
       (vec_concat:V2SI
         (plus:SI
           (minus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_operand:V4HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_operand:V4HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (minus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:SI
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 0)])))))
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 2)])))))))))]
  "TARGET_AMETHYST"
  "pdmacccc.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmaccccq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (plus:V2DI
         (sign_extend:V2DI
           (match_operand:V2SI 3 "register_operand" "r"))
         (vec_concat:V2DI
           (plus:DI
             (minus:DI
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_operand:V4HI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_operand:V4HI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (minus:DI
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:DI
             (plus:DI
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 0)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 1)]))))
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 0)])))))
             (plus:DI
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))))))))]
  "TARGET_AMETHYST"
  "pdmaccccq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmacccc_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (vec_concat:V2SI
       (plus:SI
         (minus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (minus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))
       (plus:SI
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 1)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 0)])))))
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 3)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))))))]
  "TARGET_AMETHYST"
  "pdzmacccc.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmaccccq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (vec_concat:V2DI
         (plus:DI
           (minus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (minus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:DI
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 0)])))))
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 2)])))))))))]
  "TARGET_AMETHYST"
  "pdzmaccccq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmsubcc_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (minus:V2SI
       (match_operand:V2SI 3 "register_operand" "r")
       (vec_concat:V2SI
         (plus:SI
           (minus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_operand:V4HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_operand:V4HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (minus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:SI
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 0)])))))
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 2)])))))))))]
  "TARGET_AMETHYST"
  "pdmsubcc.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmsubccq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (minus:V2DI
         (sign_extend:V2DI
           (match_operand:V2SI 3 "register_operand" "r"))
         (vec_concat:V2DI
           (plus:DI
             (minus:DI
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_operand:V4HI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_operand:V4HI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (minus:DI
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:DI
             (plus:DI
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 0)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 1)]))))
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 0)])))))
             (plus:DI
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))))))))]
  "TARGET_AMETHYST"
  "pdmsubccq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmsubcc_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (neg:V2SI
       (vec_concat:V2SI
         (plus:SI
           (minus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_operand:V4HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_operand:V4HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (minus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:SI
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 1)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 0)])))))
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 3)])))
               (sign_extend:SI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 2)])))))))))]
  "TARGET_AMETHYST"
  "pdzmsubcc.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmsubccq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (neg:V2DI
         (vec_concat:V2DI
           (plus:DI
             (minus:DI
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_operand:V4HI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_operand:V4HI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (minus:DI
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:DI
             (plus:DI
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 0)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 1)]))))
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 1)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 0)])))))
             (plus:DI
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))
               (mult:DI
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 1)
                     (parallel [(const_int 3)])))
                 (sign_extend:DI
                   (vec_select:HI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))))))))]
  "TARGET_AMETHYST"
  "pdzmsubccq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmacccr_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (plus:V2HI
       (match_operand:V2HI 3 "register_operand" "r")
       (vec_concat:V2HI
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V2QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 0)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pwmacccr.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmacccrq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (plus:V2SI
         (sign_extend:V2SI
           (match_operand:V2HI 3 "register_operand" "r"))
         (vec_concat:V2SI
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V2QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))))))]
  "TARGET_AMETHYST"
  "pwmacccrq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmacccr_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (vec_concat:V2HI
       (plus:HI
         (mult:HI
           (sign_extend:HI
             (vec_select:QI
               (match_operand:V4QI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:HI
             (vec_select:QI
               (match_operand:V2QI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:HI
           (sign_extend:HI
             (vec_select:QI
               (match_dup 1)
               (parallel [(const_int 2)])))
           (sign_extend:HI
             (vec_select:QI
               (match_dup 2)
               (parallel [(const_int 1)])))))
       (plus:HI
         (mult:HI
           (sign_extend:HI
             (vec_select:QI
               (match_dup 1)
               (parallel [(const_int 0)])))
           (sign_extend:HI
             (vec_select:QI
               (match_dup 2)
               (parallel [(const_int 0)]))))
         (mult:HI
           (sign_extend:HI
             (vec_select:QI
               (match_dup 1)
               (parallel [(const_int 2)])))
           (sign_extend:HI
             (vec_select:QI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pwzmacccr.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmacccrq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (vec_concat:V2SI
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:QI
                 (match_operand:V4QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:QI
                 (match_operand:V2QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:SI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:SI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pwzmacccrq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmsubcr_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (minus:V2HI
       (match_operand:V2HI 3 "register_operand" "r")
       (vec_concat:V2HI
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V2QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 0)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pwmsubcr.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmsubcrq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (minus:V2SI
         (sign_extend:V2SI
           (match_operand:V2HI 3 "register_operand" "r"))
         (vec_concat:V2SI
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V2QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))))))]
  "TARGET_AMETHYST"
  "pwmsubcrq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmsubcr_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (neg:V2HI
       (vec_concat:V2HI
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V2QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 0)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pwzmsubcr.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwzmsubcrq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (neg:V2SI
         (vec_concat:V2SI
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V2QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))))))]
  "TARGET_AMETHYST"
  "pwzmsubcrq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pwmacccr_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (plus:V2SI
       (match_operand:V2SI 3 "register_operand" "r")
       (vec_concat:V2SI
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_operand:V2HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:SI
             (match_operand:HI 2 "register_operand" "r")))
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 0)])))
           (sign_extend:SI
             (match_dup 2))))))]
  "TARGET_AMETHYST"
  "pwmacccr.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmacccrq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (plus:V2DI
         (sign_extend:V2DI
           (match_operand:V2SI 3 "register_operand" "r"))
         (vec_concat:V2DI
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:DI
               (match_operand:HI 2 "register_operand" "r")))
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:DI
               (match_dup 2)))))))]
  "TARGET_AMETHYST"
  "pwmacccrq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmacccr_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (vec_concat:V2SI
       (mult:SI
         (sign_extend:SI
           (vec_select:HI
             (match_operand:V2HI 1 "register_operand" "r")
             (parallel [(const_int 0)])))
         (sign_extend:SI
           (match_operand:HI 2 "register_operand" "r")))
       (mult:SI
         (sign_extend:SI
           (vec_select:HI
             (match_dup 1)
             (parallel [(const_int 0)])))
         (sign_extend:SI
           (match_dup 2)))))]
  "TARGET_AMETHYST"
  "pwzmacccr.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmacccrq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (vec_concat:V2DI
         (mult:DI
           (sign_extend:DI
             (vec_select:HI
               (match_operand:V2HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:DI
             (match_operand:HI 2 "register_operand" "r")))
         (mult:DI
           (sign_extend:DI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 0)])))
           (sign_extend:DI
             (match_dup 2))))))]
  "TARGET_AMETHYST"
  "pwzmacccrq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmsubcr_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (minus:V2SI
       (match_operand:V2SI 3 "register_operand" "r")
       (vec_concat:V2SI
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_operand:V2HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:SI
             (match_operand:HI 2 "register_operand" "r")))
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 0)])))
           (sign_extend:SI
             (match_dup 2))))))]
  "TARGET_AMETHYST"
  "pwmsubcr.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwmsubcrq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (minus:V2DI
         (sign_extend:V2DI
           (match_operand:V2SI 3 "register_operand" "r"))
         (vec_concat:V2DI
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:DI
               (match_operand:HI 2 "register_operand" "r")))
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:DI
               (match_dup 2)))))))]
  "TARGET_AMETHYST"
  "pwmsubcrq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmsubcr_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (neg:V2SI
       (vec_concat:V2SI
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_operand:V2HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:SI
             (match_operand:HI 2 "register_operand" "r")))
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 0)])))
           (sign_extend:SI
             (match_dup 2))))))]
  "TARGET_AMETHYST"
  "pwzmsubcr.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pwzmsubcrq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (neg:V2DI
         (vec_concat:V2DI
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:DI
               (match_operand:HI 2 "register_operand" "r")))
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:DI
               (match_dup 2)))))))]
  "TARGET_AMETHYST"
  "pwzmsubcrq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmacccr_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (plus:V2HI
       (match_operand:V2HI 3 "register_operand" "r")
       (vec_concat:V2HI
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V4QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 0)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pdmacccr.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmacccrq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (plus:V2SI
         (sign_extend:V2SI
           (match_operand:V2HI 3 "register_operand" "r"))
         (vec_concat:V2SI
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V4QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))))))]
  "TARGET_AMETHYST"
  "pdmacccrq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmacccr_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (vec_concat:V2HI
       (plus:HI
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V8QI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_operand:V4QI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 4)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 6)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))
       (plus:HI
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 0)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:HI
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 4)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 2)]))))
           (mult:HI
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 1)
                 (parallel [(const_int 6)])))
             (sign_extend:HI
               (vec_select:QI
                 (match_dup 2)
                 (parallel [(const_int 3)]))))))))]
  "TARGET_AMETHYST"
  "pdzmacccr.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmacccrq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (vec_concat:V2SI
         (plus:SI
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V8QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_operand:V4QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:SI
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 0)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:SI
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:SI
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (sign_extend:SI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pdzmacccrq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmsubcr_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (minus:V2HI
       (match_operand:V2HI 3 "register_operand" "r")
       (vec_concat:V2HI
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V4QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 0)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pdmsubcr.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmsubcrq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (minus:V2SI
         (sign_extend:V2SI
           (match_operand:V2HI 3 "register_operand" "r"))
         (vec_concat:V2SI
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V4QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))))))]
  "TARGET_AMETHYST"
  "pdmsubcrq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmsubcr_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (neg:V2HI
       (vec_concat:V2HI
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V8QI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_operand:V4QI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)]))))))
         (plus:HI
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 0)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:HI
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 4)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 2)]))))
             (mult:HI
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 1)
                   (parallel [(const_int 6)])))
               (sign_extend:HI
                 (vec_select:QI
                   (match_dup 2)
                   (parallel [(const_int 3)])))))))))]
  "TARGET_AMETHYST"
  "pdzmsubcr.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdzmsubcrq_b"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
     (ss_truncate:V2HI
       (neg:V2SI
         (vec_concat:V2SI
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V8QI 1 "register_operand" "r")
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_operand:V4QI 2 "register_operand" "r")
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))
           (plus:SI
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 0)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 0)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 2)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 1)])))))
             (plus:SI
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 4)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 2)]))))
               (mult:SI
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 1)
                     (parallel [(const_int 6)])))
                 (sign_extend:SI
                   (vec_select:QI
                     (match_dup 2)
                     (parallel [(const_int 3)]))))))))))]
  "TARGET_AMETHYST"
  "pdzmsubcrq.b\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "amethyst_simd_pdmacccr_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (plus:V2SI
       (match_operand:V2SI 3 "register_operand" "r")
       (vec_concat:V2SI
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V2HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pdmacccr.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmacccrq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (plus:V2DI
         (sign_extend:V2DI
           (match_operand:V2SI 3 "register_operand" "r"))
         (vec_concat:V2DI
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V2HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 0)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))))))]
  "TARGET_AMETHYST"
  "pdmacccrq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmacccr_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (vec_concat:V2SI
       (plus:SI
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_operand:V4HI 1 "register_operand" "r")
               (parallel [(const_int 0)])))
           (sign_extend:SI
             (vec_select:HI
               (match_operand:V2HI 2 "register_operand" "r")
               (parallel [(const_int 0)]))))
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 2)])))
           (sign_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 1)])))))
       (plus:SI
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 0)])))
           (sign_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 0)]))))
         (mult:SI
           (sign_extend:SI
             (vec_select:HI
               (match_dup 1)
               (parallel [(const_int 2)])))
           (sign_extend:SI
             (vec_select:HI
               (match_dup 2)
               (parallel [(const_int 1)])))))))]
  "TARGET_AMETHYST"
  "pdzmacccr.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmacccrq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (vec_concat:V2DI
         (plus:DI
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_operand:V4HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_operand:V2HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:DI
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 0)]))))
           (mult:DI
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:DI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pdzmacccrq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmsubcr_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (minus:V2SI
       (match_operand:V2SI 3 "register_operand" "r")
       (vec_concat:V2SI
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V2HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pdmsubcr.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdmsubcrq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (minus:V2DI
         (sign_extend:V2DI
           (match_operand:V2SI 3 "register_operand" "r"))
         (vec_concat:V2DI
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V2HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 0)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))))))]
  "TARGET_AMETHYST"
  "pdmsubcrq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmsubcr_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (neg:V2SI
       (vec_concat:V2SI
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V4HI 1 "register_operand" "r")
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_operand:V2HI 2 "register_operand" "r")
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)])))))
         (plus:SI
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 0)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 0)]))))
           (mult:SI
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 1)
                 (parallel [(const_int 2)])))
             (sign_extend:SI
               (vec_select:HI
                 (match_dup 2)
                 (parallel [(const_int 1)]))))))))]
  "TARGET_AMETHYST"
  "pdzmsubcr.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

(define_insn "amethyst_simd_pdzmsubcrq_h"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_truncate:V2SI
       (neg:V2DI
         (vec_concat:V2DI
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V4HI 1 "register_operand" "r")
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_operand:V2HI 2 "register_operand" "r")
                   (parallel [(const_int 0)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))
           (plus:DI
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 0)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 0)]))))
             (mult:DI
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 1)
                   (parallel [(const_int 2)])))
               (sign_extend:DI
                 (vec_select:HI
                   (match_dup 2)
                   (parallel [(const_int 1)])))))))))]
  "TARGET_AMETHYST"
  "pdzmsubcrq.h\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "DI")])

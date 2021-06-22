;; Crypto Extension Instructions.
;; Copyright (C) 2021 Free Software Foundation, Inc.
;; Contributed by Thomas Sailer (t.sailer@alumni.ethz.ch).
;; Based on MIPS target for GNU compiler.

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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; AES
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define_insn "riscv_aes32esmi"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (xor:SI
      (match_operand:SI 1 "register_operand" "r")
      (rotate:SI
        (unspec:SI
          [(truncate:QI
             (lshiftrt:SI
               (match_operand:SI 2 "register_operand" "r")
               (ashift:SI
                 (match_operand:QI 3 "const_crypto_aes_bytelane" "")
                 (const_int 3))))] UNSPEC_AES32ESMI)
        (ashift:SI
          (match_dup 3)
          (const_int 3)))))]
  "TARGET_ZKNE && !TARGET_64BIT"
  "aes32esmi\t%0,%1,%2"
  [(set_attr "type" "crypto")])

(define_insn "riscv_aes32esi"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (xor:SI
      (match_operand:SI 1 "register_operand" "r")
      (rotate:SI
        (unspec:SI
          [(truncate:QI
             (lshiftrt:SI
               (match_operand:SI 2 "register_operand" "r")
               (ashift:SI
                 (match_operand:QI 3 "const_crypto_aes_bytelane" "")
                 (const_int 3))))] UNSPEC_AES32ESI)
        (ashift:SI
          (match_dup 3)
          (const_int 3)))))]
  "TARGET_ZKNE && !TARGET_64BIT"
  "aes32esi\t%0,%1,%2"
  [(set_attr "type" "crypto")])

(define_insn "riscv_aes32dsmi"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (xor:SI
      (match_operand:SI 1 "register_operand" "r")
      (rotate:SI
        (unspec:SI
          [(truncate:QI
             (lshiftrt:SI
               (match_operand:SI 2 "register_operand" "r")
               (ashift:SI
                 (match_operand:QI 3 "const_crypto_aes_bytelane" "")
                 (const_int 3))))] UNSPEC_AES32DSMI)
        (ashift:SI
          (match_dup 3)
          (const_int 3)))))]
  "TARGET_ZKND && !TARGET_64BIT"
  "aes32dsmi\t%0,%1,%2"
  [(set_attr "type" "crypto")])

(define_insn "riscv_aes32dsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (xor:SI
      (match_operand:SI 1 "register_operand" "r")
      (rotate:SI
        (unspec:SI
          [(truncate:QI
             (lshiftrt:SI
               (match_operand:SI 2 "register_operand" "r")
               (ashift:SI
                 (match_operand:QI 3 "const_crypto_aes_bytelane" "")
                 (const_int 3))))] UNSPEC_AES32DSI)
        (ashift:SI
          (match_dup 3)
          (const_int 3)))))]
  "TARGET_ZKND && !TARGET_64BIT"
  "aes32dsi\t%0,%1,%2"
  [(set_attr "type" "crypto")])

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; SHA-256
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define_insn "riscv_sha256sig0"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (xor:SI
      (xor:SI
        (rotatert:SI
          (match_operand:SI 1 "register_operand" "r")
          (const_int 7))
        (rotatert:SI
          (match_dup 1)
          (const_int 18)))
      (lshiftrt:SI
        (match_dup 1)
        (const_int 3))))]
  "TARGET_ZKNH"
  "sha256sig0\t%0,%1"
  [(set_attr "type" "crypto")])

(define_insn "riscv_sha256sig1"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (xor:SI
      (xor:SI
        (rotatert:SI
          (match_operand:SI 1 "register_operand" "r")
          (const_int 17))
        (rotatert:SI
          (match_dup 1)
          (const_int 19)))
      (lshiftrt:SI
        (match_dup 1)
        (const_int 10))))]
  "TARGET_ZKNH"
  "sha256sig1\t%0,%1"
  [(set_attr "type" "crypto")])

(define_insn "riscv_sha256sum0"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (xor:SI
      (xor:SI
        (rotatert:SI
          (match_operand:SI 1 "register_operand" "r")
          (const_int 2))
        (rotatert:SI
          (match_dup 1)
          (const_int 13)))
      (rotatert:SI
        (match_dup 1)
        (const_int 22))))]
  "TARGET_ZKNH"
  "sha256sum0\t%0,%1"
  [(set_attr "type" "crypto")])

(define_insn "riscv_sha256sum1"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (xor:SI
      (xor:SI
        (rotatert:SI
          (match_operand:SI 1 "register_operand" "r")
          (const_int 6))
        (rotatert:SI
          (match_dup 1)
          (const_int 11)))
      (rotatert:SI
        (match_dup 1)
        (const_int 25))))]
  "TARGET_ZKNH"
  "sha256sum1\t%0,%1"
  [(set_attr "type" "crypto")])

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; SHA-512
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define_insn "riscv_sha512sum0r"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (xor:SI
      (xor:SI
        (xor:SI
          (ashift:SI
            (match_operand:SI 1 "register_operand" "r")
            (const_int 25))
          (ashift:SI
            (match_dup 1)
            (const_int 30)))
        (lshiftrt:SI
          (match_dup 1)
          (const_int 28)))
      (xor:SI
        (xor:SI
          (lshiftrt:SI
            (match_operand:SI 2 "register_operand" "r")
            (const_int 7))
          (lshiftrt:SI
            (match_dup 2)
            (const_int 2)))
        (ashift:SI
          (match_dup 2)
          (const_int 4)))))]
  "TARGET_ZKNH && !TARGET_64BIT"
  "sha512sum0r\t%0,%1,%2"
  [(set_attr "type" "crypto")])

(define_insn "riscv_sha512sum1r"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (xor:SI
      (xor:SI
        (xor:SI
          (ashift:SI
            (match_operand:SI 1 "register_operand" "r")
            (const_int 23))
          (lshiftrt:SI
            (match_dup 1)
            (const_int 14)))
        (lshiftrt:SI
          (match_dup 1)
          (const_int 18)))
      (xor:SI
        (xor:SI
          (lshiftrt:SI
            (match_operand:SI 2 "register_operand" "r")
            (const_int 9))
          (ashift:SI
            (match_dup 2)
            (const_int 18)))
        (ashift:SI
          (match_dup 2)
          (const_int 14)))))]
  "TARGET_ZKNH && !TARGET_64BIT"
  "sha512sum1r\t%0,%1,%2"
  [(set_attr "type" "crypto")])

(define_insn "riscv_sha512sig0l"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (xor:SI
      (xor:SI
        (xor:SI
          (lshiftrt:SI
            (match_operand:SI 1 "register_operand" "r")
            (const_int 1))
          (lshiftrt:SI
            (match_dup 1)
            (const_int 7)))
        (lshiftrt:SI
          (match_dup 1)
          (const_int 8)))
      (xor:SI
        (xor:SI
          (ashift:SI
            (match_operand:SI 2 "register_operand" "r")
            (const_int 31))
          (ashift:SI
            (match_dup 2)
            (const_int 25)))
        (ashift:SI
          (match_dup 2)
          (const_int 24)))))]
  "TARGET_ZKNH && !TARGET_64BIT"
  "sha512sig0l\t%0,%1,%2"
  [(set_attr "type" "crypto")])

(define_insn "riscv_sha512sig0h"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (xor:SI
      (xor:SI
        (xor:SI
          (lshiftrt:SI
            (match_operand:SI 1 "register_operand" "r")
            (const_int 1))
          (lshiftrt:SI
            (match_dup 1)
            (const_int 7)))
        (lshiftrt:SI
          (match_dup 1)
          (const_int 8)))
      (xor:SI
        (ashift:SI
          (match_operand:SI 2 "register_operand" "r")
          (const_int 31))
        (ashift:SI
          (match_dup 2)
          (const_int 24)))))]
  "TARGET_ZKNH && !TARGET_64BIT"
  "sha512sig0h\t%0,%1,%2"
  [(set_attr "type" "crypto")])

(define_insn "riscv_sha512sig1l"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (xor:SI
      (xor:SI
        (xor:SI
          (ashift:SI
            (match_operand:SI 1 "register_operand" "r")
            (const_int 3))
          (lshiftrt:SI
            (match_dup 1)
            (const_int 6)))
        (lshiftrt:SI
          (match_dup 1)
          (const_int 19)))
      (xor:SI
        (xor:SI
          (ashift:SI
            (match_operand:SI 2 "register_operand" "r")
            (const_int 26))
          (ashift:SI
            (match_dup 2)
            (const_int 13)))
        (lshiftrt:SI
          (match_dup 2)
          (const_int 29)))))]
  "TARGET_ZKNH && !TARGET_64BIT"
  "sha512sig1l\t%0,%1,%2"
  [(set_attr "type" "crypto")])

(define_insn "riscv_sha512sig1h"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (xor:SI
      (xor:SI
        (xor:SI
          (ashift:SI
            (match_operand:SI 1 "register_operand" "r")
            (const_int 3))
          (lshiftrt:SI
            (match_dup 1)
            (const_int 6)))
        (lshiftrt:SI
          (match_dup 1)
          (const_int 19)))
      (xor:SI
        (ashift:SI
          (match_operand:SI 2 "register_operand" "r")
          (const_int 13))
        (lshiftrt:SI
          (match_dup 2)
          (const_int 29)))))]
  "TARGET_ZKNH && !TARGET_64BIT"
  "sha512sig1h\t%0,%1,%2"
  [(set_attr "type" "crypto")])

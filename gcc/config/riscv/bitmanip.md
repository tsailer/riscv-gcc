;; Machine description for RISC-V Bit Manipulation operations.
;; Copyright (C) 2019 Free Software Foundation, Inc.

;; This file is part of GCC.

;; GCC is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 3, or (at your option)
;; any later version.

;; GCC is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

(define_code_iterator bitmanip_bitwise [and ior])

(define_code_iterator any_minmax [smin smax umin umax])

(define_code_iterator clz_ctz_cpop [clz ctz popcount])

(define_code_attr bitmanip_optab [(smin "smin")
				  (smax "smax")
				  (umin "umin")
				  (umax "umax")
				  (clz "clz")
				  (ctz "ctz")
				  (popcount "popcount")])

(define_code_attr bitmanip_insn [(smin "min")
				 (smax "max")
				 (umin "minu")
				 (umax "maxu")
				 (clz "clz")
				 (ctz "ctz")
				 (popcount "cpop")])

(define_mode_attr shiftm1 [(SI "const31_operand") (DI "const63_operand")])

(define_insn "<bitmanip_optab>si2"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(clz_ctz_cpop:SI (match_operand:SI 1 "register_operand" "r")))]
  "TARGET_ZBB"
  { return TARGET_64BIT ? "<bitmanip_insn>w\t%0,%1" : "<bitmanip_insn>\t%0,%1"; }
  [(set_attr "type" "bitmanip")])

;; TODO: In theory zero_extend should be OK to combine too, since the output
;;       range is 0 ~ 32, zero_extend or sign_extend will get same result.
(define_insn "*<bitmanip_optab>disi2"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI
	  (clz_ctz_cpop:SI (match_operand:SI 1 "register_operand" "r"))))]
  "TARGET_64BIT && TARGET_ZBB"
  "<bitmanip_insn>w\t%0,%1"
  [(set_attr "type" "bitmanip")])

(define_insn "<bitmanip_optab>di2"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(clz_ctz_cpop:DI (match_operand:DI 1 "register_operand" "r")))]
  "TARGET_64BIT && TARGET_ZBB"
  "<bitmanip_insn>\t%0,%1"
  [(set_attr "type" "bitmanip")])

(define_insn "*<optab>_not<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(bitmanip_bitwise:X (not:X (match_operand:X 1 "register_operand" "r"))
			    (match_operand:X 2 "register_operand" "r")))]
  "TARGET_ZBB || TARGET_ZBP"
  "<insn>n\t%0,%2,%1"
  [(set_attr "type" "bitmanip")])

(define_insn "*xor_not<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(not:X (xor:X (match_operand:X 1 "register_operand" "r")
		      (match_operand:X 2 "register_operand" "r"))))]
  "TARGET_ZBB || TARGET_ZBP"
  "xnor\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_packsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(ior:SI (zero_extend:SI (match_operand:HI 1 "register_operand" "r"))
		(ashift:SI (zero_extend:SI (match_operand:HI 2 "register_operand" "r")) (const_int 16))))]
  "TARGET_ZBP || TARGET_ZBE || TARGET_ZBF"
  { return TARGET_64BIT ? "packw\t%0,%1,%2" : "pack\t%0,%1,%2"; }
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_packdi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(ior:DI (zero_extend:DI (match_operand:SI 1 "register_operand" "r"))
		(ashift:DI (zero_extend:DI (match_operand:SI 2 "register_operand" "r")) (const_int 32))))]
  "(TARGET_ZBP || TARGET_ZBE || TARGET_ZBF) && TARGET_64BIT"
  "pack\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_packusi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(ior:SI (lshiftrt:SI (match_operand:SI 1 "register_operand" "r") (const_int 16))
		(ashift:SI (lshiftrt:SI (match_operand:SI 2 "register_operand" "r") (const_int 16)) (const_int 16))))]
  "TARGET_ZBP"
  { return TARGET_64BIT ? "packuw\t%0,%1,%2" : "packu\t%0,%1,%2"; }
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_packudi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(ior:DI (lshiftrt:DI (match_operand:DI 1 "register_operand" "r") (const_int 32))
		(ashift:DI (lshiftrt:DI (match_operand:DI 2 "register_operand" "r") (const_int 32)) (const_int 32))))]
  "TARGET_ZBP && TARGET_64BIT"
  "packu\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_packh<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(ior:X (zero_extend:X (match_operand:QI 1 "register_operand" "r"))
	       (ashift:X (zero_extend:X (match_operand:QI 2 "register_operand" "r")) (const_int 8))))]
  "TARGET_ZBP || TARGET_ZBE || TARGET_ZBF"
  "packh\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "*zero_extendhi<GPR:mode>2_bitmanip"
  [(set (match_operand:GPR 0 "register_operand" "=r,r")
	(zero_extend:GPR (match_operand:HI 1 "nonimmediate_operand" "r,m")))]
  "TARGET_ZBB || TARGET_ZBP"
  "@
   zext.h\t%0,%1
   lhu\t%0,%1"
  [(set_attr "type" "bitmanip,load")])

(define_insn "*zero_extendsidi2_bitmanip"
  [(set (match_operand:DI 0 "register_operand" "=r,r")
	(zero_extend:DI (match_operand:SI 1 "nonimmediate_operand" "r,m")))]
  "TARGET_64BIT && (TARGET_ZBB || TARGET_ZBA)"
  "@
   zext.w\t%0,%1
   lwu\t%0,%1"
  [(set_attr "type" "bitmanip,load")])

(define_insn "<bitmanip_optab><mode>3"
  [(set (match_operand:X 0 "register_operand" "=r")
	(any_minmax:X (match_operand:X 1 "register_operand" "r")
		      (match_operand:X 2 "register_operand" "r")))]
  "TARGET_ZBB"
  "<bitmanip_insn>\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "*bset<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(ior:X (ashift:X (const_int 1)
			 (match_operand:QI 2 "register_operand" "r"))
	       (match_operand:X 1 "register_operand" "r")))]
  "TARGET_ZBS"
  "bset\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "*bset<mode>_mask"
  [(set (match_operand:X 0 "register_operand" "=r")
	(ior:X (ashift:X (const_int 1)
			 (subreg:QI
			  (and:X (match_operand:X 2 "register_operand" "r")
				 (match_operand 3 "<X:shiftm1>" "i")) 0))
	       (match_operand:X 1 "register_operand" "r")))]
  "TARGET_ZBS"
  "bset\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "*bset<mode>_1"
  [(set (match_operand:X 0 "register_operand" "=r")
	(ashift:X (const_int 1)
		  (match_operand:QI 1 "register_operand" "r")))]
  "TARGET_ZBS"
  "bset\t%0,x0,%1"
  [(set_attr "type" "bitmanip")])

(define_insn "*bset<mode>_1_mask"
  [(set (match_operand:X 0 "register_operand" "=r")
	(ashift:X (const_int 1)
		  (subreg:QI
		   (and:X (match_operand:X 1 "register_operand" "r")
			  (match_operand 2 "<X:shiftm1>" "i")) 0)))]
  "TARGET_ZBS"
  "bset\t%0,x0,%1"
  [(set_attr "type" "bitmanip")])

(define_insn "*bseti<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(ior:X (match_operand:X 1 "register_operand" "r")
	       (match_operand 2 "single_bit_mask_operand" "i")))]
  "TARGET_ZBS"
  "bseti\t%0,%1,%S2"
  [(set_attr "type" "bitmanip")])

(define_insn "*bsetw"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI
	 (subreg:SI
	  (ior:DI (subreg:DI
		   (ashift:SI (const_int 1)
			      (match_operand:QI 2 "register_operand" "r")) 0)
		  (match_operand:DI 1 "register_operand" "r")) 0)))]
  "TARGET_64BIT && TARGET_ZBS"
  "bsetw\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "*bsetw_mask"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI
	 (subreg:SI
	  (ior:DI (subreg:DI
		   (ashift:SI
		    (const_int 1)
		    (subreg:QI
		     (and:DI (match_operand:DI 2 "register_operand" "r")
			     (match_operand 3 "const31_operand" "i")) 0)) 0)
		  (match_operand:DI 1 "register_operand" "r")) 0)))]
  "TARGET_64BIT && TARGET_ZBS"
  "bsetw\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "*bsetiw"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(ior:DI (sign_extend:DI (match_operand:SI 1 "register_operand" "r"))
		(match_operand 2 "single_bit_mask_operand" "i")))]
  "TARGET_64BIT && TARGET_ZBS"
  "bsetiw\t%0,%1,%S2"
  [(set_attr "type" "bitmanip")])

(define_insn "*bclr<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(and:X (rotate:X (const_int -2)
			 (match_operand:QI 2 "register_operand" "r"))
	       (match_operand:X 1 "register_operand" "r")))]
  "TARGET_ZBS"
  "bclr\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "*bclri<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(and:X (match_operand:X 1 "register_operand" "r")
	       (match_operand 2 "not_single_bit_mask_operand" "i")))]
  "TARGET_ZBS"
  "bclri\t%0,%1,%T2"
  [(set_attr "type" "bitmanip")])

(define_insn "*bclrw"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI
	 (subreg:SI
	  (and:DI
	   (not:DI (subreg:DI
		    (ashift:SI (const_int 1)
			       (match_operand:QI 2 "register_operand" "r")) 0))
	   (match_operand:DI 1 "register_operand" "r")) 0)))]
  "TARGET_64BIT && TARGET_ZBS"
  "bclrw\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "*bclriw"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(and:DI (sign_extend:DI (match_operand:SI 1 "register_operand" "r"))
		(match_operand 2 "not_single_bit_mask_operand" "i")))]
  "TARGET_64BIT && TARGET_ZBS"
  "bclriw\t%0,%1,%T2"
  [(set_attr "type" "bitmanip")])

(define_insn "*binv<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(xor:X (ashift:X (const_int 1)
			 (match_operand:QI 2 "register_operand" "r"))
	       (match_operand:X 1 "register_operand" "r")))]
  "TARGET_ZBS"
  "binv\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "*binvi<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(xor:X (match_operand:X 1 "register_operand" "r")
	       (match_operand 2 "single_bit_mask_operand" "i")))]
  "TARGET_ZBS"
  "binvi\t%0,%1,%S2"
  [(set_attr "type" "bitmanip")])

(define_insn "*binvw"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI
	 (subreg:SI
	  (xor:DI (subreg:DI
		   (ashift:SI (const_int 1)
			      (match_operand:QI 2 "register_operand" "r")) 0)
		  (match_operand:DI 1 "register_operand" "r")) 0)))]
  "TARGET_64BIT && TARGET_ZBS"
  "binvw\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "*binviw"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(xor:DI (sign_extend:DI (match_operand:SI 1 "register_operand" "r"))
		(match_operand 2 "single_bit_mask_operand" "i")))]
  "TARGET_64BIT && TARGET_ZBS"
  "binviw\t%0,%1,%S2"
  [(set_attr "type" "bitmanip")])

(define_insn "*bext<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(zero_extract:X (match_operand:X 1 "register_operand" "r")
			(const_int 1)
			(zero_extend:X
			 (match_operand:QI 2 "register_operand" "r"))))]
  "TARGET_ZBS"
  "bext\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "*bexti"
  [(set (match_operand:X 0 "register_operand" "=r")
	(zero_extract:X (match_operand:X 1 "register_operand" "r")
			(const_int 1)
			(match_operand 2 "immediate_operand" "i")))]
  "TARGET_ZBS"
  "bexti\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "*bextw"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(and:DI
	 (subreg:DI
	  (lshiftrt:SI (match_operand:SI 1 "register_operand" "r")
		       (match_operand:QI 2 "register_operand" "r")) 0)
	 (const_int 1)))]
  "TARGET_64BIT && TARGET_ZBS"
  "bextw\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_slosi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(not:SI (ashift:SI (not:SI (match_operand:SI 1 "register_operand" "r"))
			   (match_operand:QI 2 "arith_operand" "rI"))))]
  "TARGET_ZBB || TARGET_ZBP"
  { return TARGET_64BIT ? "slo%i2w\t%0,%1,%2" : "slo%i2\t%0,%1,%2"; }
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_slodi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(not:DI (ashift:DI (not:DI (match_operand:DI 1 "register_operand" "r"))
			   (match_operand:QI 2 "arith_operand" "rI"))))]
  "TARGET_64BIT && (TARGET_ZBB || TARGET_ZBP)"
  "slo%i2\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_srosi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(not:SI (lshiftrt:SI (not:SI (match_operand:SI 1 "register_operand" "r"))
			     (match_operand:QI 2 "arith_operand" "rI"))))]
  "TARGET_ZBB || TARGET_ZBP"
  { return TARGET_64BIT ? "sro%i2w\t%0,%1,%2" : "sro%i2\t%0,%1,%2"; }
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_srodi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(not:DI (lshiftrt:DI (not:DI (match_operand:DI 1 "register_operand" "r"))
			     (match_operand:QI 2 "arith_operand" "rI"))))]
  "TARGET_64BIT && (TARGET_ZBB || TARGET_ZBP)"
  "sro%i2\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "rotrsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(rotatert:SI (match_operand:SI 1 "register_operand" "r")
		     (match_operand:QI 2 "arith_operand" "rI")))]
  "TARGET_ZBB || TARGET_ZBP"
  { return TARGET_64BIT ? "ror%i2w\t%0,%1,%2" : "ror%i2\t%0,%1,%2"; }
  [(set_attr "type" "bitmanip")])

(define_insn "rotrdi3"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(rotatert:DI (match_operand:DI 1 "register_operand" "r")
		     (match_operand:QI 2 "arith_operand" "rI")))]
  "TARGET_64BIT && (TARGET_ZBB || TARGET_ZBP)"
  "ror%i2\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_expand "riscv_rolw"
  [(match_operand:SI 0 "register_operand" "=r")
   (match_operand:SI 1 "register_operand" "r")
   (match_operand:SI 2 "register_operand" "r")]
  "TARGET_64BIT && (TARGET_ZBB || TARGET_ZBP)"
{
  emit_insn (gen_rotlsi3 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "rotlsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(rotate:SI (match_operand:SI 1 "register_operand" "r")
		   (match_operand:QI 2 "register_operand" "r")))]
  "TARGET_ZBB || TARGET_ZBP"
  { return TARGET_64BIT ? "rolw\t%0,%1,%2" : "rol\t%0,%1,%2"; }
  [(set_attr "type" "bitmanip")])

(define_insn "rotldi3"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(rotate:DI (match_operand:DI 1 "register_operand" "r")
		   (match_operand:QI 2 "register_operand" "r")))]
  "TARGET_64BIT && (TARGET_ZBB || TARGET_ZBP)"
  "rol\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "rotlsi3_sext"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI (rotate:SI (match_operand:SI 1 "register_operand" "r")
				   (match_operand:QI 2 "register_operand" "r"))))]
  "TARGET_64BIT && (TARGET_ZBB || TARGET_ZBP)"
  "rolw\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_grevsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		    (match_operand:QI 2 "arith_operand" "rI")] UNSPEC_GREV32))]
  "TARGET_ZBP"
  { return TARGET_64BIT ? "grev%i2w\t%0,%1,%2" : "grev%i2\t%0,%1,%2"; }
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_grevdi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		    (match_operand:QI 2 "arith_operand" "rI")] UNSPEC_GREV64))]
  "TARGET_64BIT && TARGET_ZBP"
  "grev%i2\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

;;; ??? assembler doesn't accept rev8
(define_insn "bswapsi2"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(bswap:SI (match_operand:SI 1 "register_operand" "r")))]
  "TARGET_ZBP"
  { return TARGET_64BIT ? "greviw\t%0,%1,0x18" : "grevi\t%0,%1,0x18"; }
  [(set_attr "type" "bitmanip")])

;;; ??? assembler doesn't accept rev8
(define_insn "bswapdi2"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(bswap:DI (match_operand:DI 1 "register_operand" "r")))]
  "TARGET_64BIT && TARGET_ZBP"
  "grevi\t%0,%1,0x38"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_gorcsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		    (match_operand:QI 2 "arith_operand" "rI")] UNSPEC_GORC32))]
  "TARGET_ZBP"
  { return TARGET_64BIT ? "gorc%i2w\t%0,%1,%2" : "gorc%i2\t%0,%1,%2"; }
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_gorcdi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		    (match_operand:QI 2 "arith_operand" "rI")] UNSPEC_GORC64))]
  "TARGET_64BIT && TARGET_ZBP"
  "gorc%i2\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_shflsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		    (match_operand:QI 2 "arith_operand" "rI")] UNSPEC_SHFL32))]
  "TARGET_ZBP"
  { return TARGET_64BIT ? "shfl%i2w\t%0,%1,%2" : "shfl%i2\t%0,%1,%2"; }
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_shfldi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		    (match_operand:QI 2 "arith_operand" "rI")] UNSPEC_SHFL64))]
  "TARGET_64BIT && TARGET_ZBP"
  "shfl%i2\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_unshflsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		    (match_operand:QI 2 "arith_operand" "rI")] UNSPEC_UNSHFL32))]
  "TARGET_ZBP"
  { return TARGET_64BIT ? "unshfl%i2w\t%0,%1,%2" : "unshfl%i2\t%0,%1,%2"; }
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_unshfldi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		    (match_operand:QI 2 "arith_operand" "rI")] UNSPEC_UNSHFL64))]
  "TARGET_64BIT && TARGET_ZBP"
  "unshfl%i2\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_xpermn<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec:X [(match_operand:X 1 "register_operand" "r")
		   (match_operand:X 2 "register_operand" "r")] UNSPEC_XPERMN))]
  "TARGET_ZBP"
  "xperm.n\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_xpermb<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec:X [(match_operand:X 1 "register_operand" "r")
		   (match_operand:X 2 "register_operand" "r")] UNSPEC_XPERMB))]
  "TARGET_ZBP"
  "xperm.b\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_xpermh<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec:X [(match_operand:X 1 "register_operand" "r")
		   (match_operand:X 2 "register_operand" "r")] UNSPEC_XPERMH))]
  "TARGET_ZBP"
  "xperm.h\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_xpermw<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec:X [(match_operand:X 1 "register_operand" "r")
		   (match_operand:X 2 "register_operand" "r")] UNSPEC_XPERMW))]
  "TARGET_ZBP && TARGET_64BIT"
  "xperm.w\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_bmextsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		    (match_operand:SI 2 "register_operand" "r")] UNSPEC_BMEXT32))]
  "TARGET_ZBE"
  { return TARGET_64BIT ? "bmextw\t%0,%1,%2" : "bmext\t%0,%1,%2"; }
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_bmextdi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		    (match_operand:DI 2 "register_operand" "r")] UNSPEC_BMEXT64))]
  "TARGET_64BIT && TARGET_ZBE"
  "bmext\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_bmdepsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		    (match_operand:SI 2 "register_operand" "r")] UNSPEC_BMDEP32))]
  "TARGET_ZBE"
  { return TARGET_64BIT ? "bmdepw\t%0,%1,%2" : "bmdep\t%0,%1,%2"; }
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_bmdepdi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		    (match_operand:DI 2 "register_operand" "r")] UNSPEC_BMDEP64))]
  "TARGET_64BIT && TARGET_ZBE"
  "bmdep\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_clmulsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(truncate:SI (unspec:DI [(match_operand:SI 1 "register_operand" "r")
				 (match_operand:SI 2 "register_operand" "r")] UNSPEC_CLMUL)))]
  "TARGET_ZBC && !TARGET_64BIT"
  "clmul\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_clmulhsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(truncate:SI (lshiftrt:DI (unspec:DI [(match_operand:SI 1 "register_operand" "r")
					      (match_operand:SI 2 "register_operand" "r")] UNSPEC_CLMUL) (const_int 16))))]
  "TARGET_ZBC && !TARGET_64BIT"
  "clmulh\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_clmulrsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(truncate:SI (lshiftrt:DI (unspec:DI [(match_operand:SI 1 "register_operand" "r")
					      (match_operand:SI 2 "register_operand" "r")] UNSPEC_CLMUL) (const_int 15))))]
  "TARGET_ZBC && !TARGET_64BIT"
  "clmulr\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_clmuldi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(truncate:DI (unspec:TI [(match_operand:DI 1 "register_operand" "r")
				 (match_operand:DI 2 "register_operand" "r")] UNSPEC_CLMUL)))]
  "TARGET_ZBC && TARGET_64BIT"
  "clmul\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_clmulhdi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(truncate:DI (lshiftrt:TI (unspec:TI [(match_operand:DI 1 "register_operand" "r")
					      (match_operand:DI 2 "register_operand" "r")] UNSPEC_CLMUL) (const_int 32))))]
  "TARGET_ZBC && TARGET_64BIT"
  "clmulh\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_clmulrdi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(truncate:DI (lshiftrt:TI (unspec:TI [(match_operand:DI 1 "register_operand" "r")
					      (match_operand:DI 2 "register_operand" "r")] UNSPEC_CLMUL) (const_int 31))))]
  "TARGET_ZBC && TARGET_64BIT"
  "clmulr\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_crc32b<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec:X [(match_operand:X 1 "register_operand" "r") (const_int 8)] UNSPEC_CRC32))]
  "TARGET_ZBR"
  "crc32.b\t%0,%1"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_crc32h<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec:X [(match_operand:X 1 "register_operand" "r") (const_int 16)] UNSPEC_CRC32))]
  "TARGET_ZBR"
  "crc32.h\t%0,%1"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_crc32w<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec:X [(match_operand:X 1 "register_operand" "r") (const_int 32)] UNSPEC_CRC32))]
  "TARGET_ZBR"
  "crc32.w\t%0,%1"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_crc32d<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec:X [(match_operand:X 1 "register_operand" "r") (const_int 64)] UNSPEC_CRC32))]
  "TARGET_ZBR && TARGET_64BIT"
  "crc32.d\t%0,%1"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_crc32cb<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec:X [(match_operand:X 1 "register_operand" "r") (const_int 8)] UNSPEC_CRC32C))]
  "TARGET_ZBR"
  "crc32c.b\t%0,%1"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_crc32ch<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec:X [(match_operand:X 1 "register_operand" "r") (const_int 16)] UNSPEC_CRC32C))]
  "TARGET_ZBR"
  "crc32c.h\t%0,%1"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_crc32cw<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec:X [(match_operand:X 1 "register_operand" "r") (const_int 32)] UNSPEC_CRC32C))]
  "TARGET_ZBR"
  "crc32c.w\t%0,%1"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_crc32cd<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec:X [(match_operand:X 1 "register_operand" "r") (const_int 64)] UNSPEC_CRC32C))]
  "TARGET_ZBR && TARGET_64BIT"
  "crc32c.d\t%0,%1"
  [(set_attr "type" "bitmanip")])

;;; ??? bmat

(define_insn "*cmix"
  [(set (match_operand:X 0 "register_operand" "=r")
	(xor:X (and:X (xor:X (match_operand:X 1 "register_operand" "r")
			     (match_operand:X 3 "register_operand" "r"))
		      (match_operand:X 2 "register_operand" "r"))
	       (match_dup 3)))]
  "TARGET_ZBT"
  "cmix\t%0,%2,%1,%3"
  [(set_attr "type" "bitmanip")])

;; ??? Can we do this by using the % communtative constraint?

(define_insn "*cmix2"
  [(set (match_operand:X 0 "register_operand" "=r")
	(xor:X (and:X (xor:X (match_operand:X 1 "register_operand" "r")
			     (match_operand:X 3 "register_operand" "r"))
		      (match_operand:X 2 "register_operand" "r"))
	       (match_dup 1)))]
  "TARGET_ZBT"
  "cmix\t%0,%2,%3,%1"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_cmov<mode>"
  [(set (match_operand:X 0 "register_operand")
	(if_then_else:X (ne:X (match_operand:X 1 "register_operand") (const_int 0))
			(match_operand:X 2 "register_operand")
			(match_operand:X 3 "register_operand")))]
  "TARGET_ZBT"
  "cmov\t%0,%1,%2,%3"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_fslsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (truncate:SI
       (lshiftrt:DI
	 (rotate:DI
	   (ior:DI
	     (ashift:DI (zero_extend:DI (match_operand:SI 1 "register_operand" "r")) (const_int 32))
	     (zero_extend:DI (match_operand:SI 2 "register_operand" "r")))
	   (match_operand:QI 3 "arith_operand" "rI")) (const_int 32))))]
  "TARGET_ZBT"
  { return TARGET_64BIT ? "fsl%i2w\t%0,%1,%2,%3" : "fsl%i2\t%0,%1,%2,%3"; }
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_fsldi"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (truncate:DI
       (lshiftrt:TI
	 (rotate:TI
	   (ior:TI
	     (ashift:TI (zero_extend:TI (match_operand:DI 1 "register_operand" "r")) (const_int 64))
	     (zero_extend:TI (match_operand:DI 2 "register_operand" "r")))
	   (match_operand:QI 3 "arith_operand" "rI")) (const_int 64))))]
  "TARGET_64BIT && TARGET_ZBT"
  "fsl%i2\t%0,%1,%2,%3"
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_fsrsi"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (truncate:SI
       (rotatert:DI
	 (ior:DI
	   (ashift:DI (zero_extend:DI (match_operand:SI 1 "register_operand" "r")) (const_int 32))
	   (zero_extend:DI (match_operand:SI 2 "register_operand" "r")))
	 (match_operand:QI 3 "arith_operand" "rI"))))]
  "TARGET_ZBT"
  { return TARGET_64BIT ? "fsr%i2w\t%0,%1,%2,%3" : "fsr%i2\t%0,%1,%2,%3"; }
  [(set_attr "type" "bitmanip")])

(define_insn "riscv_fsrdi"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (truncate:DI
       (rotatert:TI
	 (ior:TI
	   (ashift:TI (zero_extend:TI (match_operand:DI 1 "register_operand" "r")) (const_int 64))
	   (zero_extend:TI (match_operand:DI 2 "register_operand" "r")))
	 (match_operand:QI 3 "arith_operand" "rI"))))]
  "TARGET_64BIT && TARGET_ZBT"
  "fsr%i2\t%0,%1,%2,%3"
  [(set_attr "type" "bitmanip")])

(define_insn "*shNadd"
  [(set (match_operand:X 0 "register_operand" "=r")
	(plus:X (ashift:X (match_operand:X 1 "register_operand" "r")
			  (match_operand:QI 2 "immediate_operand" "I"))
		(match_operand:X 3 "register_operand" "r")))]
  "TARGET_ZBA
   && (INTVAL (operands[2]) >= 1) && (INTVAL (operands[2]) <= 3)"
  "sh%2add\t%0,%1,%3"
  [(set_attr "type" "bitmanip")])

(define_insn "*shNadduw"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(plus:DI
	 (and:DI (ashift:DI (match_operand:DI 1 "register_operand" "r")
			    (match_operand:QI 2 "immediate_operand" "I"))
		 (match_operand 3 "immediate_operand" ""))
	 (match_operand:DI 4 "register_operand" "r")))]
  "TARGET_64BIT && TARGET_ZBA
   && (INTVAL (operands[2]) >= 1) && (INTVAL (operands[2]) <= 3)
   && (INTVAL (operands[3]) >> INTVAL (operands[2])) == 0xffffffff"
  "sh%2addu.w\t%0,%1,%4"
  [(set_attr "type" "bitmanip")])

(define_insn "*addu.w"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(plus:DI (zero_extend:DI
		  (match_operand:SI 1 "register_operand" "r"))
		 (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_64BIT && TARGET_ZBA"
  "addu.w\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

(define_insn "*slliuw"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(and:DI (ashift:DI (match_operand:DI 1 "register_operand" "r")
			   (match_operand:QI 2 "immediate_operand" "I"))
		(match_operand 3 "immediate_operand" "")))]
  "TARGET_64BIT && TARGET_ZBA
   && (INTVAL (operands[3]) >> INTVAL (operands[2])) == 0xffffffff"
  "slliu.w\t%0,%1,%2"
  [(set_attr "type" "bitmanip")])

;; ??? bfxp

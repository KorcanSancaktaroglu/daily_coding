; ==============================================================================
; File: multiplication-subroutine.asm
; Description: Optimized multiplication using repeated addition.
;              Uses self-modifying return logic to read parameters.
; ==============================================================================

ORG 100
        BSA MVE      ; Call multiplication subroutine
        DEC 100      ; Parameter 1: Multiplicand
        DEC -3       ; Parameter 2: Multiplier (Counter)
        STA SUM      ; Result stored here
        HLT

MVE,    HEX 0        ; Return address
        LDA MVE I    ; Read Multiplicand
        STA VAL
        ISZ MVE
        LDA MVE I    ; Read Multiplier
        STA CTR
        ISZ MVE      ; Point to return instruction
        CLA
LOP,    ADD VAL
        ISZ CTR
        BUN LOP
        BUN MVE I    ; Return to main

VAL,    HEX 0
CTR,    HEX 0
SUM,    HEX 0
        END

; ==============================================================================
; File: memory-copy.asm
; Description: Transfers a block of data from one memory range to another.
; ==============================================================================

ORG 0
        BSA copy     ; Call copy subroutine
        HEX 300      ; Param 1: Source Start
        HEX 400      ; Param 2: Dest Start
        DEC -50      ; Param 3: Loop Counter
        HLT

copy,   HEX 0
        LDA copy I
        STA PT1
        ISZ copy
        LDA copy I
        STA PT2
        ISZ copy
        LDA copy I
        STA CTR
        ISZ copy

loop,   LDA PT1 I
        STA PT2 I
        ISZ PT1
        ISZ PT2
        ISZ CTR
        BUN loop
        BUN copy I

PT1,    HEX 0
PT2,    HEX 0
CTR,    DEC 0
        END

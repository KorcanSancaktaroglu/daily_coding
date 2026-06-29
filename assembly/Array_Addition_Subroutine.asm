; ==============================================================================
; File: array-addition.asm
; Description: Performs vector addition (C[i] = A[i] + B[i]) 
;              using dynamic pointer addressing via subroutine parameters.
; ==============================================================================

ORG 0
        BSA ADD_ARRAYS    ; Call subroutine
        HEX 300           ; Parameter 1: Source A address
        HEX 400           ; Parameter 2: Source B address
        HEX 500           ; Parameter 3: Destination address
        DEC -50           ; Parameter 4: Loop counter (size)
        HLT               ; Return point

ADD_ARRAYS, HEX 0         ; Subroutine entry point / Return pointer
        
        ; --- Load Parameters ---
        LDA ADD_ARRAYS I  ; Load pointer to array A
        STA PT1
        ISZ ADD_ARRAYS    ; Increment pointer
        
        LDA ADD_ARRAYS I  ; Load pointer to array B
        STA PT2
        ISZ ADD_ARRAYS
        
        LDA ADD_ARRAYS I  ; Load pointer to target C
        STA PT3
        ISZ ADD_ARRAYS
        
        LDA ADD_ARRAYS I  ; Load counter
        STA CTR
        ISZ ADD_ARRAYS    ; Adjust return address for HLT

; --- Processing Loop ---
LOOP,   LDA PT1 I         ; Load A[i]
        ADD PT2 I         ; Add B[i]
        STA PT3 I         ; Store in C[i]
        
        ISZ PT1           ; Increment pointers
        ISZ PT2
        ISZ PT3
        
        ISZ CTR           ; Increment counter until 0
        BUN LOOP          ; Repeat
        
        BUN ADD_ARRAYS I  ; Return to main program

; --- Data Variables ---
PT1,    HEX 0
PT2,    HEX 0
PT3,    HEX 0
CTR,    DEC 0
        END

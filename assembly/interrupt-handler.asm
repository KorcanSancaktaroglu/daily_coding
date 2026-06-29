; ==============================================================================
; File: interrupt-handler.asm
; Description: Optimized Interrupt Service Routine (ISR) for I/O handling.
;              Features self-modifying code (SMC) for high-performance buffering.
; ==============================================================================

ORG 0
        ; Vector table for hardware interrupts
        ZRO,    HEX 0           ; Hardware writes Return PC here
        BUN     ISR_ROUTINE     ; Jump to service routine

        ORG 100
MAIN,   CLA                     ; Clear Accumulator
        ION                     ; Enable interrupts
        ; ... Main program logic ...
        BUN     MAIN

        ; =========================================================
        ; INTERRUPT SERVICE ROUTINE (ISR)
        ; =========================================================
        ORG 200
ISR_ROUTINE, STA SAC            ; Save Accumulator (AC) to backup

CHK_IN, SKI                     ; Check if input flag is set
        BUN     CHK_OUT         ; If not, check output flag
        
        INP                     ; Read input character
        OUT                     ; Echo to output display
        
        ; --- Optimized Self-Modifying Code (SMC) ---
        ; Instead of indirect addressing, we modify the instruction operand directly.
WRITE,  STA 500                 ; Store input at target address (dynamic)
        ISZ WRITE               ; Increment operand: next time it becomes STA 501, etc.
        BUN     EXIT_ISR

CHK_OUT, SKO                    ; Check if output flag is set
        BUN     EXIT_ISR        ; If neither, exit

EXIT_ISR, LDA SAC               ; Restore Accumulator
        ION                     ; Re-enable interrupts
        BUN     ZRO I           ; Return to Main program

SAC,    HEX 0                   ; AC backup variable
        END

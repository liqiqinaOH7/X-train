	AREA Get_now_speed, CODE, READONLY
	EXPORT  __getNowSpeed
    
__getNowSpeed PROC
    PUSH {r4-r12} ; Save caller registers
;r4 - speed_stock[0]
;r5 - speed_stock[1]
;r6 - time_stock[3]
;r7 - time_stock[1] | time_stock[2]
;r8 - k 
;r9 - nowtime
;r10 - delta_t 
    IMPORT cleared_flag
    IMPORT real_speed
    IMPORT speed_stock_count
    IMPORT speed_stock
    IMPORT time_stock
    IMPORT get_now_time_result

    LDR r1, =cleared_flag
    LDR r1, [r1]
    CMP r1, #0
    BEQ return_real_speed

    LDR r2, =speed_stock_count
    LDR r2, [r2]
    CMP r2, #0
    BEQ speed_count_eq_zero
    
    B speed_count_non_zero

speed_count_eq_zero
    LDR r4, =speed_stock
    LDR r6, =time_stock + 12 ; Load address of time_stock[3] to r6
    LDR r1, [r6] ; Load time_stock[3]
    LDR r7, =time_stock + 4 ; Load address of time_stock[1] to r7
    LDR r2, [r7] ; Load time_stock[1]
    SUB r3, r1, r2
    ASR r3, r3, #1

    LDR r1, =time_stock + 8 ; Load the address of time_stock[2] into r1
    LDR r1, [r1] ; Load time_stock[2]
    ADD r3, r3, r1 ; r3 now holds delta_t

    ; delta_t needs to be stored back to memory
    ; Assuming the address of delta_t is in r10
    STR r3, [r10] ; Store delta_t

    LDR r1, [r4, #4] ; Load speed_stock[1] 
    LDR r2, [r4] ; Load speed_stock[0]
    SUB r9, r1, r2 ; r9 now has the numerator of k

    ; for the denominator, we need to load delta_t
    LDR r3, [r10]

    ; Calculating K
    SDIV r8, r9, r3

    ; nowtime = Get_now_time_result - time_stock[3] / 2 + delta_t;
    LDR r1, =get_now_time_result
    LDR r1, [r1]
	LDR r2, [r6]
    ASR r0, r2 , #1 ; r0 = time_stock[3] / 2
    SUB r1, r1, r0 
    ADD r9, r1, r3 ; r9 now holds 'nowtime'

    B proceed

speed_count_non_zero
    ; Code for non-zero speed_count
    ; delta_t = time_stock[0] + (time_stock[1] - time_stock[3]) / 2;
    LDR r7, =time_stock ; Load address of time_stock[0] into r7
    LDR r0, [r7] ; Load time_stock[0] into r0
    LDR r1, =time_stock + 4 ; Load the address of time_stock[1] into r1
    LDR r1, [r1] ; Load time_stock[1] into r1
	LDR r2, [r6]
    SUB r2, r1, r2 ; Subtract time_stock[3] from time_stock[1]
    ASR r3, r2, #1 ; Right shift r2 by 1 to divide by 2
    ADD r3, r3, r0 ; Add time_stock[0] to r3 to calculate delta_t
    STR r3, [r10] ; Store delta_t

    ; k = (speed_stock[0] - speed_stock[1]) / delta_t;
    LDR r1, [r4] ; Load speed_stock[0] into r1
    LDR r5, =speed_stock + 4 ; Load the address of speed_stock[1] into r5
    LDR r2, [r5] ; Load speed_stock[1] into r2
    SUB r9, r1, r2 ; Subtract speed_stock[1] from speed_stock[0] to calculate the numerator of k
    ; Load delta_t from memory for the denominator of k
    LDR r3, [r10]
    ; Calculate k
    SDIV r8, r9, r3

    ; nowtime = Get_now_time_counter(0) - time_stock[1] / 2 + delta_t;
    LDR r1, =get_now_time_result
    LDR r0, [r1] ; Load Get_now_time_counter into r0
	LDR r2, [r7]
    ASR r1, r2 , #1 ; Right shift time_stock[1] by 1 to divide by 2
    SUB r1, r0, r1 
    ADD r9, r1, r3 ; r9 now holds 'nowtime'

    B proceed

proceed
    ; Calculate k * nowtime and store result in r0
    MUL r0, r8, r9

    ; Add speed_stock[0] to the result
    LDR r4, [r4] ; Load speed_stock[0]
    ADD r0, r0, r4 ; Final result is in r0

    POP {r4-r12} ; Restore the caller registers

    BX lr

return_real_speed
    LDR r0, =real_speed ; Code assumes r0 is where the result should be
	LDR r0, [r0]
    POP {r4-r12} ; Restore the caller registers

    BX lr
ENDP
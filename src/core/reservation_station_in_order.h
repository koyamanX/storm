#ifndef RESERVATION_STATION_IN_ORDER_H
#define RESERVATION_STATION_IN_ORDER_H

#include "reorder_buffer.h"
#include "reservation_station.h"
#include "uops.h"

#define RS_IN_ORDER_NUM_OF_ENTRIES 4.0
#define LOG2_RS_IN_ORDER_NUM_OF_ENTRIES _int(_log10(RS_IN_ORDER_NUM_OF_ENTRIES)/_log10(2.0))

declare reservation_station_in_order {
    input Valid;
    input Op[SIZEOF_UOP_T];
    input Vj[32];
    input Vk[32];
    input Qj[ROB_TAG_SIZE];
    input Qk[ROB_TAG_SIZE];
    input Dest[ROB_TAG_SIZE];
    input A[32];
    func_in issue(Valid, Op, Vj, Vk, Qj, Qk, Dest, A);
    func_in flush();
    func_out full();
    func_in stall();
    output dispatch_Op[SIZEOF_UOP_T];
    output dispatch_Dest[ROB_TAG_SIZE];
    output dispatch_Vj[32];
    output dispatch_Qk[ROB_TAG_SIZE];
    output dispatch_Vk[32];
    output dispatch_A[32];
    func_out dispatch(dispatch_Op, dispatch_Dest, dispatch_Vj, dispatch_Qk, dispatch_Vk, dispatch_A);
    input CDB0Id[ROB_TAG_SIZE];
    input CDB0Val[32];
    func_in CDB0(CDB0Id, CDB0Val);
    input CDB1Id[ROB_TAG_SIZE];
    input CDB1Val[32];
    func_in CDB1(CDB1Id, CDB1Val);
    input CDB2Id[ROB_TAG_SIZE];
    input CDB2Val[32];
    func_in CDB2(CDB2Id, CDB2Val);
    input CDB3Id[ROB_TAG_SIZE];
    input CDB3Val[32];
    func_in CDB3(CDB3Id, CDB3Val);
}

#endif

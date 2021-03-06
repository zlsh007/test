/*
 *  Copyright (C) 2002 - 2003 Ardis Technolgies <roman@ardistech.com>
 *  Copyright (C) 2007 - 2016 Vladislav Bolkhovitin
 *  Copyright (C) 2007 - 2016 SanDisk Corporation
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation, version 2
 *  of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 */

#ifndef ISCSI_HDR_H
#define ISCSI_HDR_H
#include "types.h"

#define __packed __attribute__ ((packed))
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))
#define ARRAY_SIZE_MAX 1024*1024

/* Opcode encoding bits */
#define ISCSI_OP_RETRY			0x80
#define ISCSI_OP_IMMEDIATE		0x40
#define ISCSI_OPCODE_MASK		0x3F

/* Client to Server Message Opcode values */
#define ISCSI_OP_NOP_OUT		0x00
#define ISCSI_OP_SCSI_CMD		0x01
#define ISCSI_OP_SCSI_TASK_MGT_MSG	0x02
#define ISCSI_OP_LOGIN_CMD		0x03
#define ISCSI_OP_TEXT_CMD		0x04
#define ISCSI_OP_SCSI_DATA		0x05
#define ISCSI_OP_LOGOUT_CMD		0x06
#define ISCSI_OP_SNACK_CMD		0x10

/* Server to Client Message Opcode values */
#define ISCSI_OP_NOP_IN			0x20
#define ISCSI_OP_SCSI_RSP		0x21
#define ISCSI_OP_SCSI_TASK_MGT_RSP	0x22
#define ISCSI_OP_LOGIN_RSP		0x23
#define ISCSI_OP_TEXT_RSP		0x24
#define ISCSI_OP_SCSI_DATA_IN		0x25
#define ISCSI_OP_LOGOUT_RSP		0x26
#define ISCSI_OP_R2T_RSP		0x31
#define ISCSI_OP_ASYNC_EVENT		0x32
#define ISCSI_OP_REJECT_MSG		0x3f

#define ISCSI_CMD_FINAL		0x80
#define ISCSI_CMD_READ		0x40
#define ISCSI_CMD_WRITE		0x20
#define ISCSI_CMD_ATTR_MASK	0x07
#define ISCSI_CMD_UNTAGGED	0x00
#define ISCSI_CMD_SIMPLE	0x01
#define ISCSI_CMD_ORDERED	0x02
#define ISCSI_CMD_HEAD_OF_QUEUE	0x03
#define ISCSI_CMD_ACA		0x04

enum {
        SCST_DATA_UNKNOWN = 0,
        SCST_DATA_WRITE,
        SCST_DATA_READ,
        SCST_DATA_BIDI, /* read | write */
        SCST_DATA_NONE,
};

const char *SCST_DATA_DIR[] = {
        [SCST_DATA_UNKNOWN]     = "UNKNOWN",
        [SCST_DATA_WRITE]       = "WRITE",
        [SCST_DATA_READ]        = "READ",
        [SCST_DATA_BIDI]        = "BIDI",
        [SCST_DATA_NONE]        = "NONE",
};

#define ISCSI_AHSTYPE_CDB		1
#define ISCSI_AHSTYPE_RLENGTH		2

#define ISCSI_FLG_CONTINUE		0x40
#define ISCSI_FLG_FINAL			0x80
#define ISCSI_FLG_TRANSIT		0x80
#define ISCSI_FLG_CSG_SECURITY		0x00
#define ISCSI_FLG_CSG_LOGIN		0x04
#define ISCSI_FLG_CSG_FULL_FEATURE	0x0c
#define ISCSI_FLG_CSG_MASK		0x0c
#define ISCSI_FLG_NSG_SECURITY		0x00
#define ISCSI_FLG_NSG_LOGIN		0x01
#define ISCSI_FLG_NSG_FULL_FEATURE	0x03
#define ISCSI_FLG_NSG_MASK		0x03
#define ISCSI_FLG_RESIDUAL_UNDERFLOW		0x02
#define ISCSI_FLG_RESIDUAL_OVERFLOW		0x04
#define ISCSI_FLG_BIRESIDUAL_UNDERFLOW		0x08
#define ISCSI_FLG_BIRESIDUAL_OVERFLOW		0x10

#define ISCSI_RESPONSE_COMMAND_COMPLETED	0x00
#define ISCSI_RESPONSE_TARGET_FAILURE		0x01

/* Login Status response classes */
#define ISCSI_STATUS_SUCCESS		0x00
#define ISCSI_STATUS_REDIRECT		0x01
#define ISCSI_STATUS_INITIATOR_ERR	0x02
#define ISCSI_STATUS_TARGET_ERR		0x03

/* Login Status response detail codes */
/* Class-0 (Success) */
#define ISCSI_STATUS_ACCEPT		0x00

/* Class-1 (Redirection) */
#define ISCSI_STATUS_TGT_MOVED_TEMP	0x01
#define ISCSI_STATUS_TGT_MOVED_PERM	0x02

/* Class-2 (Initiator Error) */
#define ISCSI_STATUS_INIT_ERR		0x00
#define ISCSI_STATUS_AUTH_FAILED	0x01
#define ISCSI_STATUS_TGT_FORBIDDEN	0x02
#define ISCSI_STATUS_TGT_NOT_FOUND	0x03
#define ISCSI_STATUS_TGT_REMOVED	0x04
#define ISCSI_STATUS_NO_VERSION		0x05
#define ISCSI_STATUS_TOO_MANY_CONN	0x06
#define ISCSI_STATUS_MISSING_FIELDS	0x07
#define ISCSI_STATUS_CONN_ADD_FAILED	0x08
#define ISCSI_STATUS_INV_SESSION_TYPE	0x09
#define ISCSI_STATUS_SESSION_NOT_FOUND	0x0a
#define ISCSI_STATUS_INV_REQ_TYPE	0x0b

/* Class-3 (Target Error) */
#define ISCSI_STATUS_TARGET_ERROR	0x00
#define ISCSI_STATUS_SVC_UNAVAILABLE	0x01
#define ISCSI_STATUS_NO_RESOURCES	0x02

#define ISCSI_RESERVED_TAG		0xffffffff

#define ISCSI_REASON_NO_FULL_FEATURE_PHASE	0x01
#define ISCSI_REASON_DATA_DIGEST_ERROR		0x02
#define ISCSI_REASON_DATA_SNACK_REJECT		0x03
#define ISCSI_REASON_PROTOCOL_ERROR		0x04
#define ISCSI_REASON_UNSUPPORTED_COMMAND	0x05
#define ISCSI_REASON_IMMEDIATE_COMMAND_REJECT	0x06
#define ISCSI_REASON_TASK_IN_PROGRESS		0x07
#define ISCSI_REASON_INVALID_SNACK		0x08
#define ISCSI_REASON_INVALID_PDU_FIELD		0x09
#define ISCSI_REASON_BOOKMARK_REJECT		0x0a
#define ISCSI_REASON_NEGOTIATION_RESET		0x0b
#define ISCSI_REASON_WAITING_LOGOUT		0x0c

/*************************************************************
 **  SCSI Architecture Model (SAM) Status codes. Taken from SAM-3 draft
 **  T10/1561-D Revision 4 Draft dated 7th November 2002.
 *************************************************************/
#define SAM_STAT_GOOD            0x00
#define SAM_STAT_CHECK_CONDITION 0x02
#define SAM_STAT_CONDITION_MET   0x04
#define SAM_STAT_BUSY            0x08
#define SAM_STAT_INTERMEDIATE    0x10
#define SAM_STAT_INTERMEDIATE_CONDITION_MET 0x14
#define SAM_STAT_RESERVATION_CONFLICT 0x18
#define SAM_STAT_COMMAND_TERMINATED 0x22	/* obsolete in SAM-3 */
#define SAM_STAT_TASK_SET_FULL   0x28
#define SAM_STAT_ACA_ACTIVE      0x30
#define SAM_STAT_TASK_ABORTED    0x40

#define FIFO_STORAGE "storage_data"
#define FIFO_SOCKET  "socket_data"

struct fifo_hdr {
        int hdr_size;
        char encrypt;
        char decrypt;
        char name[0];
};

struct iscsi_hdr {
	u8  opcode;			/* 0 */
	u8  flags;
	u8  spec1[2];
	u8  ahslength;			/* 4 */
	u8  datalength[3];
	u16 lun[4];			/* 8 */
	u32 itt;			/* 16 */
	u32 ttt;			/* 20 */
	u32 sn;				/* 24 */
	u32 exp_sn;			/* 28 */
	u32 max_sn;			/* 32 */
	u32 spec3[3];			/* 36 */
} __packed;				/* 48 */

struct iscsi_scsi_rsp_hdr {
	u8  opcode;
	u8  flags;
	u8  response;
	u8  cmd_status;
	u8  ahslength;
	u8  datalength[3];
	u32 rsvd1[2];
	__be32 itt;
	__be32 snack;
	u32 stat_sn;
	u32 exp_cmd_sn;
	u32 max_cmd_sn;
	u32 exp_data_sn;
	__be32 bi_residual_count;
	__be32 residual_count;
} __packed;

struct iscsi_sense_data {
	__be16 length;
	u8  data[0];
} __packed;

struct iscsi_ahs_hdr {
	u16 ahslength;
	u8 ahstype;
} __packed;

struct iscsi_task_mgt_hdr {
	u8  opcode;
	u8  function;
	__be16 rsvd1;
	u8  ahslength;
	u8  datalength[3];
	__be64 lun;
	__be32 itt;
	__be32 rtt;
	u32 cmd_sn;
	u32 exp_stat_sn;
	u32 ref_cmd_sn;
	u32 exp_data_sn;
	u32 rsvd2[2];
} __packed;

union iscsi_sid {
	struct {
		u8 isid[6];		/* Initiator Session ID */
		u16 tsih;		/* Target Session ID */
	} id;
	u64 id64;
} __packed;

struct iscsi_scsi_cmd_hdr {
	u8  opcode;
	u8  flags;
	__be16 rsvd1;
	u8  ahslength;
	u8  datalength[3];
	__be64 lun;
	__be32 itt;
	__be32 data_length;
	u32 cmd_sn;
	u32 exp_stat_sn;
	u8  scb[16];
} __packed;

struct iscsi_data_out_hdr {
	u8  opcode;
	u8  flags;
	u16 rsvd1;
	u8  ahslength;
	u8  datalength[3];
	__be64 lun;
	__be32 itt;
	__be32 ttt;
	u32 rsvd2;
	u32 exp_stat_sn;
	u32 rsvd3;
	__be32 data_sn;
	__be32 buffer_offset;
	u32 rsvd4;
} __packed;

struct iscsi_data_in_hdr {
	u8  opcode;
	u8  flags;
	u8  rsvd1;
	u8  cmd_status;
	u8  ahslength;
	u8  datalength[3];
	u32 rsvd2[2];
	__be32 itt;
	__be32 ttt;
	u32 stat_sn;
	u32 exp_cmd_sn;
	u32 max_cmd_sn;
	__be32 data_sn;
	__be32 buffer_offset;
	__be32 residual_count;
} __packed;

struct iscsi_text_req_hdr {
	u8  opcode;
	u8  flags;
	u16 rsvd1;
	u8  ahslength;
	u8  datalength[3];
	u32 rsvd2[2];
	u32 itt;
	u32 ttt;
	u32 cmd_sn;
	u32 exp_stat_sn;
	u32 rsvd3[4];
} __packed;

struct iscsi_text_rsp_hdr {
	u8  opcode;
	u8  flags;
	u16 rsvd1;
	u8  ahslength;
	u8  datalength[3];
	u32 rsvd2[2];
	u32 itt;
	u32 ttt;
	u32 stat_sn;
	u32 exp_cmd_sn;
	u32 max_cmd_sn;
	u32 rsvd3[3];
} __packed;

struct iscsi_login_req_hdr {
	u8  opcode;
	u8  flags;
	u8  max_version;		/* Max. version supported */
	u8  min_version;		/* Min. version supported */
	u8  ahslength;
	u8  datalength[3];
	union iscsi_sid sid;
	u32 itt;			/* Initiator Task Tag */
	u16 cid;			/* Connection ID */
	u16 rsvd1;
	u32 cmd_sn;
	u32 exp_stat_sn;
	u32 rsvd2[4];
} __packed;

struct iscsi_login_rsp_hdr {
	u8  opcode;
	u8  flags;
	u8  max_version;		/* Max. version supported */
	u8  active_version;		/* Active version */
	u8  ahslength;
	u8  datalength[3];
	union iscsi_sid sid;
	u32 itt;			/* Initiator Task Tag */
	u32 rsvd1;
	u32 stat_sn;
	u32 exp_cmd_sn;
	u32 max_cmd_sn;
	u8  status_class;		/* see Login RSP Status classes below */
	u8  status_detail;		/* see Login RSP Status details below */
	u8  rsvd2[10];
} __packed;

struct iscsi_logout_req_hdr {
	u8  opcode;
	u8  flags;
	u16 rsvd1;
	u8  ahslength;
	u8  datalength[3];
	u32 rsvd2[2];
	u32 itt;
	u16 cid;
	u16 rsvd3;
	u32 cmd_sn;
	u32 exp_stat_sn;
	u32 rsvd4[4];
} __packed;

struct iscsi_logout_rsp_hdr {
	u8  opcode;
	u8  flags;
	u8  response;
	u8  rsvd1;
	u8  ahslength;
	u8  datalength[3];
	u32 rsvd2[2];
	u32 itt;
	u32 rsvd3;
	u32 stat_sn;
	u32 exp_cmd_sn;
	u32 max_cmd_sn;
	u32 rsvd4;
	u16 time2wait;
	u16 time2retain;
	u32 rsvd5;
} __packed;

struct iscsi_reject_hdr {
	u8  opcode;
	u8  flags;
	u8  reason;
	u8  rsvd1;
	u8  ahslength;
	u8  datalength[3];
	u32 rsvd2[2];
	u32 ffffffff;
	u32 rsvd3;
	u32 stat_sn;
	u32 exp_cmd_sn;
	u32 max_cmd_sn;
	u32 data_sn;
	u32 rsvd4[2];
} __packed;

#endif	/* ISCSI_HDR_H */

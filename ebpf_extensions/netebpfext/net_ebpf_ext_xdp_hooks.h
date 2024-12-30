// Copyright (c) eBPF for Windows contributors
// SPDX-License-Identifier: MIT
#pragma once
#include <stdint.h>

// This file contains APIs for hooks and helpers that are
// exposed by netebpfext.sys for use by eBPF xdp test programs.

/**
 * @brief Handle an incoming packet as early as possible.
 *
 * Program type: \ref EBPF_PROGRAM_TYPE_XDP_TEST
 *
 * @param[in] context Packet metadata.
 * @retval XDP_PASS Allow the packet to pass.
 * @retval XDP_DROP Drop the packet.
 * @retval XDP_TX Bounce the received packet back out the same NIC it arrived on.
 */
typedef xdp_action_t
xdp_hook_t(xdp_md_t* context);

// XDP_TEST helper functions.
#define XDP_EXT_HELPER_FN_BASE 0xFFFF

#define EBPF_HELPER(return_type, name, args) typedef return_type(*const name##_t) args
EBPF_HELPER(int, bpf_xdp_adjust_head, (xdp_md_t * ctx, int delta));

/**
 * @brief Adjust XDP_TEST context data pointer.
 *
 * @param[in] ctx XDP_TEST context.
 * @param[in] delta Number of bytes to move the data pointer by.
 *
 * @retval 0 The operation was successful.
 * @retval <0 A failure occurred.
 */
#ifndef __doxygen
#define bpf_xdp_adjust_head ((bpf_xdp_adjust_head_t)BPF_FUNC_xdp_adjust_head)
#endif
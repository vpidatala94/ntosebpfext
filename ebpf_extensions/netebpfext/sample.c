// Copyright (c) eBPF for Windows contributors
// SPDX-License-Identifier: MIT

/**
 * @file This file contains the definition of the layer GUIDs
 *
 */

#define INITGUID

#include "cxplat.h"
#include "ebpf_extension.h"
#include "ebpf_nethooks.h"

#include "ebpf_program_attach_type_guids.h"
#include "ebpf_program_types.h"
#include "ebpf_result.h"
#include "ebpf_windows.h"
#include "ndis.h"

#include <guiddef.h>
#include <netioapi.h>
#include <netiodef.h>
#include <specstrings.h>
#include <stdint.h>

/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "util.h"

#define DEVICE_NAME "klimt"

static void set_device(const char *radio,
		       const char *region,
		       const char *model)
{
	char device[16], name[16];

	sprintf(device, "%s%s", DEVICE_NAME, radio);
	sprintf(name, "%s%s", device, region);

	property_set("ro.product.name", name);
	property_set("ro.product.device", device);
	property_set("ro.product.model", model);
}

void vendor_load_properties()
{
	char bootloader[PROP_VALUE_MAX];

	property_get("ro.bootloader", bootloader);

	if (strstr(bootloader, "T700")) {
		/* WiFi */
		set_device("wifi", "xx", "SM-T700");
	} else if (strstr(bootloader, "T701")) {
		/* 3G */
		set_device("3g", "xx", "SM-T701");
	} else if (strstr(bootloader, "T707A")) {
		/* AT&T */
		set_device("lte", "att", "SM-T707A");
	} else if (strstr(bootloader, "T707P")) {
		/* Sprint */
		set_device("lte", "spr", "SM-T707P");
	} else if (strstr(bootloader, "T707T")) {
		/* T-Mobile */
		set_device("lte", "tmo", "SM-T707T");
	} else if (strstr(bootloader, "T707R4")) {
		/* US Cellular */
		set_device("lte", "usc", "SM-T707R4");
	} else if (strstr(bootloader, "T707V")) {
		/* Verizon */
		set_device("lte", "vzw", "SM-T707V");
	} else if (strstr(bootloader, "T705K")) {
		/* Olleh (KT) */
		set_device("lte", "ktt", "SM-T705K");
	} else if (strstr(bootloader, "T705L")) {
		/* LG Uplus */
		set_device("lte", "lgt", "SM-T705L");
	} else if (strstr(bootloader, "T705S")) {
		/* SK Telecom */
		set_device("lte", "skt", "SM-T705S");
	} else if (strstr(bootloader, "T707D")) {
		/* DoCoMo */
		set_device("lte", "dcm", "SM-T707D");
	} else if (strstr(bootloader, "T705M")) {
		/* South Americas */
		set_device("lte", "ub", "SM-T705M");
	} else if (strstr(bootloader, "T705C")) {
		/* China */
		set_device("lte", "zc", "SM-T705C");
	} else if (strstr(bootloader, "T705W")) {
		/* Canada */
		set_device("lte", "vl", "SM-T705W");
	} else if (strstr(bootloader, "T705YZ")) {
		/* Taiwan */
		set_device("lte", "zt", "SM-T705Y");
	} else if (strstr(bootloader, "T705Y")) {
		/* Oceanic */
		set_device("lte", "do", "SM-T705Y");
	} else {
		/* all other variants become International LTE */
		set_device("lte", "xx", "SM-T705");
	}
}

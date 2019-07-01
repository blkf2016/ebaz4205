/*
 * Copyright (c) 2019 blkf2016@gmail.com.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "xil_printf.h"
#include "ff.h"
#include "uboot_loader.h"

/******************************************************************************/
/**
*
* This function load u-boot.bin from fat partition
*
* @param	None.
*
* @return
*		- UBOOT_LOAD_ADDR if u-boot load is successful
*		- 0 if u-boot load is not successful
*
* @note		None.
*
****************************************************************************/
u32 UBootLoader(void)
{
    FATFS fatfs;
    FRESULT rc;
    FIL fil;
    UINT read;

    print("\r\nU-Boot loader start\r\n");

    rc = f_mount(&fatfs, "", 0);
	if(rc) {
		xil_printf("ERROR: f_mount returned %d\r\n",rc);
		goto _exit;
	}

	rc = f_open(&fil, UBOOT_BIN_NAME, FA_READ);
	if(rc) {
		xil_printf("ERROR: f_open returned %d\r\n",rc);
		goto _exit_unmount;
	}

	xil_printf("%s size: %d\r\n", UBOOT_BIN_NAME, f_size(&fil));

	rc = f_read(&fil, (void *)UBOOT_LOAD_ADDR, f_size(&fil), &read);
	if(rc) {
		xil_printf("ERROR: f_read returned %d\r\n",rc);
		goto _exit_close;
	}

	f_close(&fil);
	f_unmount("");

	xil_printf("Loaded U-Boot at 0x%08x\r\n\r\n", UBOOT_LOAD_ADDR);
    return UBOOT_LOAD_ADDR;

_exit_close:
	f_close(&fil);
_exit_unmount:
	f_unmount("");
_exit:
	print("\r\n");
    return 0;
}

#!/bin/bash

set -e

BOARD_DIR="$(dirname $0)"
GENIMAGE_TMP="${BUILD_DIR}/genimage.tmp"
GENIMAGE_CFG="${BOARD_DIR}/genimage.cfg"

for arg in "$@"
do
	case "${arg}" in
		--genimage-cfg=*)
			GENIMAGE_CFG="${arg:15}"
			echo "Use genimage config file ${GENIMAGE_CFG}"
			;;
	esac
done

rm -rf "${GENIMAGE_TMP}"

genimage                           \
	--rootpath "${TARGET_DIR}"     \
	--tmppath "${GENIMAGE_TMP}"    \
	--inputpath "${BINARIES_DIR}"  \
	--outputpath "${BINARIES_DIR}" \
	--config "${GENIMAGE_CFG}"

exit $?

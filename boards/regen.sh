#!/bin/sh

set -e
set -x
npx typescript-json-schema --noExtraProps --required --defaultNumberType integer \
		stm32.d.ts STM32DeviceConfig --out stm32deviceconfig.schema.json
npx typescript-json-schema --noExtraProps --required --defaultNumberType integer \
		stm32.d.ts STM32ArchConfig --out stm32archconfig.schema.json

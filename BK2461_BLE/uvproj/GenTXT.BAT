set curdir=%~sdp0
del ddk_fram.bin
rem ..\ext_tools\hexbin "%curdir%output\ddk_fram.hex"
rem ..\ext_tools\bin_to_crcbin "%curdir%output\ddk_fram.bin" 8192
..\ext_tools\hexbin ddk_fram.hex
..\ext_tools\bin_to_crcbin ddk_fram.bin 8192

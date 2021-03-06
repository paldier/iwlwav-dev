# common

.PHONY: always

obj-$(CPTCFG_IWLWAV)	+= tools/mtlkroot/
obj-$(CPTCFG_IWLWAV)    += mtlk.o

ifeq ($(CPTCFG_BACKPORTED_WIRELESS),y)
	CC:=$(src)/support/mtlkfront.sh $(CC)
ifeq ($(UGW_DRIVER_VERSION),)
	_REVISION_VERSION := $(shell $(src)/support/revision_info.sh $(src)/../../../../.. base)
else
	_REVISION_VERSION := $(UGW_DRIVER_VERSION)
endif
	_MTLK_VERSION := $(shell $(src)/support/mtlk_ver.pl -g < $(src)/mtlk_version)

$(obj)/wireless/driver/drv_info.c: always
	@echo "Generating drv_info.c..."
	$(shell $(src)/support/iwlwav_generate_config.sh $(src)/../../../../.. $(src) $(CFLAG) $(CC))
endif

mtlk-objs += wireless/driver/stadb.o
mtlk-objs += wireless/driver/shared/mtlk_gpl_helper.o
mtlk-objs += wireless/driver/shared/cis_manager.o
mtlk-objs += wireless/driver/shared/mtlk_tpcv4.o
mtlk-objs += wireless/driver/shared/mtlk_eeprom.o
mtlk-objs += wireless/driver/shared/eeprom_gpio.o
mtlk-objs += wireless/driver/shared/eeprom_irbd.o

mtlk-objs += wireless/shared/mtlkhash_ieee_addr.o
mtlk-objs += wireless/shared/mtlkstartup.o
mtlk-objs += wireless/shared/mtlk_wss.o
mtlk-objs += wireless/shared/mtlk_algorithms.o
mtlk-objs += wireless/shared/mtlkerr.o
ifeq ($(CPTCFG_IWLWAV_ENABLE_OBJPOOL),y)
mtlk-objs += wireless/shared/mem_leak.o
mtlk-objs += wireless/shared/mtlk_objpool.o
endif
mtlk-objs += wireless/driver/drv_info.o
mtlk-objs += wireless/driver/log_osdep.o
mtlk-objs += wireless/driver/mtlk_snprintf.o
mtlk-objs += wireless/driver/beacon_manager.o
mtlk-objs += wireless/driver/mtlk_vap_manager.o
mtlk-objs += wireless/driver/hw_mmb.o
mtlk-objs += wireless/driver/mtlk_clipboard.o
mtlk-objs += wireless/driver/mtlk_dfg_linux.o
mtlk-objs += wireless/driver/core_config.o
mtlk-objs += wireless/driver/core_stats.o
mtlk-objs += wireless/driver/mtlk_df_proc_impl.o
mtlk-objs += wireless/driver/mtlk_dfg_linux.o
mtlk-objs += wireless/driver/mcast.o
mtlk-objs += wireless/driver/txmm.o
mtlk-objs += wireless/driver/mtlk_df_user.o
mtlk-objs += wireless/driver/core.o
mtlk-objs += wireless/driver/core_dut.o
mtlk-objs += wireless/driver/scan_support.o
mtlk-objs += wireless/driver/wds.o
mtlk-objs += wireless/driver/core_common.o
mtlk-objs += wireless/driver/mtlk_serializer.o
mtlk-objs += wireless/driver/mtlk_serializer_osdep.o
mtlk-objs += wireless/driver/mtlk_df_user_tbl.o
mtlk-objs += wireless/driver/mtlk_df_linux.o
mtlk-objs += wireless/driver/mtlkaux.o
mtlk-objs += wireless/driver/utils.o
mtlk-objs += wireless/driver/eth_parser.o
mtlk-objs += wireless/driver/core_ab.o
mtlk-objs += wireless/driver/mtlk_analyzer.o
mtlk-objs += wireless/driver/ta.o
mtlk-objs += wireless/driver/mtlk_param_db.o
mtlk-objs += wireless/driver/mtlk_param_db_def.o
mtlk-objs += wireless/driver/fw_recovery.o
mtlk-objs += wireless/driver/mtlk_psdb.o
mtlk-objs += wireless/driver/osal_defs.o
mtlk-objs += wireless/driver/mtlkqos.o
mtlk-objs += wireless/driver/mtlk_mmb_drv.o
mtlk-objs += wireless/driver/mtlk_fast_mem.o
mtlk-objs += wireless/driver/core_pdb.o
mtlk-objs += wireless/driver/cache.o
mtlk-objs += wireless/driver/bitrate.o
mtlk-objs += wireless/driver/mtlk_coc.o
mtlk-objs += wireless/driver/mtlk_hs20.o
mtlk-objs += wireless/driver/mtlk_ab_manager.o
mtlk-objs += wireless/driver/frame.o
mtlk-objs += wireless/driver/mtlk_ccr_common.o
mtlk-objs += wireless/driver/mtlk_df_fw.o
mtlk-objs += wireless/driver/progmodel.o
mtlk-objs += wireless/driver/cfg80211.o
mtlk-objs += wireless/driver/mac80211.o
mtlk-objs += wireless/driver/mtlk_pcoc.o
mtlk-objs += wireless/driver/vendor_cmds.o
mtlk-objs += wireless/driver/wave_radio.o
mtlk-objs += wireless/driver/wave_radio_ab.o
mtlk-objs += wireless/driver/mtlk_ccr_pcieg5.o
mtlk-objs += wireless/driver/mtlk_ccr_pcieg6a0.o
mtlk-objs += wireless/driver/mtlk_ccr_pcieg6b0.o
mtlk-objs += wireless/driver/mtlk_ccr_pcieg6d2.o
mtlk-objs += wireless/driver/wave_fapi_if.o
mtlk-objs += wireless/driver/eth_parser.o

# Based on generated c file and therfore should be compiled last
mtlk-objs += tools/rtlogger/shared/logmacro_database.o

ccflags-y += -DLOG_LOCAL_OID=8 -DMTLK_COPYRIGHT="\"\"" -DMTLK_SOURCE_VERSION="\"$(_MTLK_VERSION).$(_REVISION_VERSION)\"" -Wno-multichar -Werror
ccflags-y += -I$(src)
ccflags-y += -I$(src)/wireless/driver
ccflags-y += -I$(src)/wireless/driver/linux
ccflags-y += -I$(src)/wireless/driver/shared
ccflags-y += -I$(src)/wireless/shared_mbss_mac
ccflags-y += -I$(src)/wireless/shared
ccflags-y += -I$(src)/tools/mtidl
ccflags-y += -I$(src)/tools/shared
ccflags-y += -I$(src)/tools/mtlkroot/linux
ccflags-y += -I$(src)/tools/mtlkroot/shared
ccflags-y += -I$(src)/tools/rtlogger/shared

ifeq ($(CPTCFG_BACKPORTED_WIRELESS),y)
clean-files := loggroups.h
clean-files += logmacros.*
clean-files += $(shell find $(obj) -name "*.scd")
clean-files += $(shell find $(obj) -name "*.o.cmd")
clean-files += $(shell find $(obj) -name "*.stderr")
clean-files += $(shell find $(obj) -name "*.pipe.result")
DIR_PREFIX:=../../../../../drivers/net/wireless/intel/iwlwav/
clean-dirs := $(shell pushd $(src) > /dev/null && find . -name ".logprep_ts" && popd > /dev/null)
clean-dirs := $(addprefix $(DIR_PREFIX),$(clean-dirs))

export abs_top=$(src)
export abs_top_srcdir=$(src)
export abs_top_builddir=$(abs_top_srcdir)
export abs_tools_srcdir=$(abs_top)/tools
export logger_origin_name = driver
export logger_binary_name = mtlk.o
export logger_origin_id = 8
endif

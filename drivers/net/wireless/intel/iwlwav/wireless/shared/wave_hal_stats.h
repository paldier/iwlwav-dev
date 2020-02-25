/************************************************************************************
*
*  File:        wave_hal_stats.h
*  Description:
*  COPYRIGHT:
*    (C) Intel India Ltd.
*    All rights are strictly reserved. Reproduction or divulgence in any
*    form whatsoever is not permitted without written authority from the
*    copyright owner. Issued by Intel India Ltd
*
**************************************************************************************/
#ifndef _HAL_STATISTICS_H_
#define _HAL_STATISTICS_H_

#define HAL_NUM_OF_ANTS             (8)
#define HAL_NUM_OF_BANDWIDTHS       (4)
#define HAL_NUM_OF_TIDS             (16)

/* Defined as per Wifi HAL values
 * 0 for 20Mhz, 1 for 40 MHz, 2 for 80 MHz, 2 for 160 MHz */
#define HAL_BW_20MHZ                (0)
#define HAL_BW_40MHZ                (1)
#define HAL_BW_80MHZ                (2)
#define HAL_BW_160MHZ               (2)

#define NUM_OF_RX_FRAMES       (4)
#define HAL_LEGACY_NSS         (0)

typedef struct _WifiAssociatedDev2_t
{
  unsigned long DataFramesSentAck;
  unsigned long DataFramesSentNoAck;
  unsigned long BytesSent;
  unsigned long BytesReceived;
  uint32 LastDataDownlinkRate;
  uint32 LastDataUplinkRate;
  uint32 Retransmissions;
  uint32 Disassociations;
  uint32 AuthenticationFailures;
  uint32 Associations;
  int SignalStrength;
  int RSSI[4];
  int MinRSSI;
  int MaxRSSI;
  unsigned char IPAddress[64];
  unsigned char OperatingStandard[64];
  unsigned char OperatingChannelBandwidth[64];
  char InterferenceSources[64];
  int8 SNR[4];
  IEEE_ADDR MACAddress;
  bool AuthenticationState;
  bool Active;
} wifiAssociatedDevDiagnostic2_t;

#define     MAX_RU_ALLOCATIONS  74
#define     MAX_BSR 32

/* below Enum is defined similar to wifi_hal.h, for validating the Tx/Rx stats */
enum Tx_Rx_flag {
  HAS_BYTES,
  HAS_MSDUS,
  HAS_MPDUS,
  HAS_PPDUS,
  HAS_BW_80P80,
  HAS_RSSI_COMB,
  HAS_RSSI_ARRAY,
};

/* Structures defined in this file are similar to wifi_hal.h structures which are used by DWPAL.
 * DWPAL fetch these structures and forward it to wifi hal as part of PLUME API's */
typedef struct _rssiSnapshot_t
{
  uint8    rssi[NUM_OF_RX_FRAMES];      /* Last 4 RSSI frames received */
  uint8    time_s[NUM_OF_RX_FRAMES];    /* Time of when last 4 RSSI were received */
  uint16   count;        /* Sequence numer of received managemant (bcn, ack) frames */
} rssiSnapshot_t;

typedef struct _PeerFlowStats_t {
  uint64 cli_rx_bytes;
  uint64 cli_tx_bytes;
  uint64 cli_rx_frames;
  uint64 cli_tx_frames;
  uint64 cli_rx_retries;
  uint64 cli_tx_retries;
  uint64 cli_rx_errors;
  uint64 cli_tx_errors;
  uint64 cli_rx_rate;
  uint64 cli_tx_rate;
  rssiSnapshot_t cli_rssi_bcn;
  rssiSnapshot_t cli_rssi_ack;
} peerFlowStats;

typedef struct _PeerRateInfoRxStats_t {
  uint8 nss;
  uint8 mcs;
  uint16 bw;
  uint64 flags;
  uint64 bytes;
  uint64 msdus;
  uint64 mpdus;
  uint64 ppdus;
  uint64 retries;
  uint8 rssi_combined;
  uint8 rssi_array[HAL_NUM_OF_ANTS][HAL_NUM_OF_BANDWIDTHS];
} peerRateInfoRxStats;

typedef struct _PeerRateInfoTxStats_t {
  uint8 nss;
  uint8 mcs;
  uint16 bw;
  uint64 flags;
  uint64 bytes;
  uint64 msdus;
  uint64 mpdus;
  uint64 ppdus;
  uint64 retries;
  uint64 attempts;
} peerRateInfoTxStats;

typedef struct _ChannelStatistics_t {
  int32 ch_number;
  uint8 ch_in_pool;
  int32 ch_noise;
  uint8 ch_radar_noise;
  int32 ch_max_80211_rssi;
  int32 ch_non_80211_noise;
  int32 ch_utilization;
  uint64 ch_utilization_total;
  uint64 ch_utilization_busy;
  uint64 ch_utilization_busy_tx;
  uint64 ch_utilization_busy_rx;
  uint64 ch_utilization_busy_self;
  uint64 ch_utilization_busy_ext;
} mtlk_channel_stats;

typedef struct _PeerTidStats_t {
  uint8 ac;
  uint8 tid;
  uint64 ewma_time_ms;
  uint64 sum_time_ms;
  uint64 num_msdus;
} peerTidStats[HAL_NUM_OF_TIDS];

/* kernel AC type definition differs from the wifi hal definiton. Hence we are using the type from wifi hal */
typedef enum
{
    WIFI_RADIO_QUEUE_TYPE_VI = 0,
    WIFI_RADIO_QUEUE_TYPE_VO,
    WIFI_RADIO_QUEUE_TYPE_BE,
    WIFI_RADIO_QUEUE_TYPE_BK,
    WIFI_RADIO_QUEUE_TYPE_CAB,
    WIFI_RADIO_QUEUE_TYPE_BCN,
    WIFI_RADIO_QUEUE_MAX_QTY,
    WIFI_RADIO_QUEUE_TYPE_NONE = -1
} wifi_radioQueueType_t;

/* Result3 data structures */
typedef enum {
    wifi_access_category_background,
    wifi_access_category_best_effort,
    wifi_access_category_video,
    wifi_access_category_voice,
} wifi_access_category_t;

typedef enum {
    WIFI_RU_TYPE_26,
    WIFI_RU_TYPE_52,
    WIFI_RU_TYPE_106,
    WIFI_RU_TYPE_242,
    WIFI_RU_TYPE_484,
    WIFI_RU_TYPE_996,
    WIFI_RU_TYPE_1024,
} wifi_ru_type_t;

typedef enum {
    WIFI_DL_MU_TYPE_NONE,
    WIFI_DL_MU_TYPE_HE,
    WIFI_DL_MU_TYPE_MIMO,
    WIFI_DL_MU_TYPE_HE_MIMO
} wifi_dl_mu_type_t;

typedef struct {
    wifi_access_category_t  access_category;
    uint32 queue_size;
} wifi_bsr_t;

typedef struct {
    wifi_ru_type_t  type;
    unsigned char   subchannels;
} wifi_ru_allocation_t;

typedef enum {
    WIFI_UL_MU_TYPE_NONE,
    WIFI_UL_MU_TYPE_HE,
} wifi_ul_mu_type_t;

typedef enum {
    wifi_twt_agreement_type_individual,
    wifi_twt_agreement_type_broadcast,
} wifi_twt_agreement_type_t;

typedef struct {
    bool implicit;
    bool announced;
    bool trigger_enabled;
} wifi_twt_operation_t;

typedef struct {
    uint32 wake_time;
    uint32 wake_interval;
    uint32 min_wake_duration;
    uint32 channel;
} wifi_twt_individual_params_t;

typedef struct {
    uint32 traget_beacon;
    uint32 listen_interval;
} wifi_twt_broadcast_params_t;

typedef struct {
    wifi_bsr_t              BufferStatus[MAX_BSR];
    wifi_ru_allocation_t    DownlinkRuAllocations[MAX_RU_ALLOCATIONS];
    wifi_dl_mu_type_t       DownlinkMuType;
    unsigned char           AllocatedDownlinkRuNum;
} wifi_dl_mu_stats_t;

typedef struct {
    wifi_bsr_t           BufferStatus[MAX_BSR];
    wifi_ru_allocation_t UplinkRuAllocations[MAX_RU_ALLOCATIONS];
    wifi_ul_mu_type_t    UpinkMuType;
    unsigned char        ChannelStateInformation;
    unsigned char        AllocatedUplinkRuNum;
} wifi_ul_mu_stats_t;

typedef struct {
    wifi_twt_agreement_type_t agreement;
    wifi_twt_operation_t      operation;
    union {
        wifi_twt_individual_params_t  individual;
        wifi_twt_broadcast_params_t   broadcast;
    } patams;
} wifi_twt_params_t;

typedef struct _WifiAssociatedDev3_t{
      /* Defination of this struct wifiAssociatedDevDiagnostic2_t
         will be committed as a part of result2 PR */
      uint64 PacketsSent;
      uint64 PacketsReceived;
      uint64 ErrorsSent;
      uint64 RetransCount;
      uint64 FailedRetransCount;
      uint64 RetryCount;
      uint64 MultipleRetryCount;
      uint32 MaxDownlinkRate;
      uint32 MaxUplinkRate;
      wifiAssociatedDevDiagnostic2_t wifiAssociatedDevDiagnostic2;
/* TOBE implemeted - FW dependency */
#if 0
      wifi_ul_mu_stats_t  UplinkMuStats;
      wifi_dl_mu_stats_t  DownlinkMuStats;
#endif
      wifi_twt_params_t   TwtParams;
} wifiAssociatedDevDiagnostic3_t;

#endif /* _HAL_STATISTICS_H_ */

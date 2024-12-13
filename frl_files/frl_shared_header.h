// ****************************************************************************
// Copyright 2014-2015 Oculus VR, Inc. All Rights reserved.
//
// Use of this software is subject to the terms of the Oculus license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ****************************************************************************


//////////////////////////////////////////////////////////////////////////////
//
//  This file is a shared interface between the C firmware program running on
//  Zelda3 boards and C++/Python programs.
//
//  Protocol format defined in https://fb.quip.com/H5H2AdNFbeBb
//
//////////////////////////////////////////////////////////////////////////////

#define StructSizeCheck(x, s) typedef int __struct_size_check[(sizeof(x) == (s)) ? 0 : -1]

#ifdef __cplusplus

  #include <cstdint>
  #define FRL_ZELDA_ENUM_CLASS      enum class
  #define FRL_ZELDA_ENUM_SIZE       : uint8_t

  #pragma pack(push, 1)

  namespace FRL
  {
    class WireFormat
    {
    public:

#else

  #define FRL_ZELDA_ENUM_CLASS      enum
  #define FRL_ZELDA_ENUM_SIZE
  #pragma pack(push, 1)

#endif

#pragma once



#define FRL_ZWF_VERIFY_VERSION					0x02	// Makes sure interface matches
#define FRL_ZWF_VERIFY_PRE						0x5A	// Makes sure interface matches
#define FRL_ZWF_VERIFY_POST						0xA5	// Makes sure interface matches

#define FRL_ZWF_PACKET_SIZE 					0x40 	// Zelda Wire Format size generic HID and CDC



FRL_ZELDA_ENUM_CLASS H2Z_commands FRL_ZELDA_ENUM_SIZE
{
  HOST_TO_ZELDA_READ				= 'r',
  HOST_TO_ZELDA_WRITE				= 'w',
  HOST_TO_ZELDA_SET_STATE			= 's',		// uint16_t ((buf[1] << 8) + buf[2]) - 16 bit fields 1=ON
  HOST_TO_ZELDA_SET_VOLTAGE			= 'v',		// uint16_t ((buf[1] << 8) + buf[2]) - set voltage on channel
  HOST_TO_ZELDA_SET_REFRESH			= 'f',		// uint16_t ((buf[1] << 8) + buf[2]) - set refresh rate in Hz
  HOST_TO_ZELDA_SET_POS_DRIVE_TIME	= 'p',		// uint16_t ((buf[1] << 8) + buf[2])
  HOST_TO_ZELDA_SET_NEG_DRIVE_TIME	= 'n',		// uint16_t ((buf[1] << 8) + buf[2])
  HOST_TO_ZELDA_SET_CLEAR_TIME	    = 'c',		// uint16_t ((buf[1] << 8) + buf[2])
  HOST_TO_ZELDA_EN_12V_BOOST		= 'e',		// buf[2] (0x00 == OFF) - enable onboard 12v boost supply
  HOST_TO_ZELDA_EN_CPLD				= 'o',		// uint16_t ((buf[1] << 8) + buf[2]) - (> 0 == ON)
  HOST_TO_ZELDA_EN_LEDS				= 'l',		// uint16_t ((buf[1] << 8) + buf[2]) -  (> 0 == ON)
  HOST_TO_ZELDA_DEBUG				= 'z',
  HOST_TO_ZELDA_EXT_TRIGGER			= 't',    	// set state change to be externally triggered or immediate
  HOST_TO_ZELDA_EXT_BIAS			= 'b',   	// uint16_t ((buf[1] << 8) + buf[2])
  HOST_TO_ZELDA_EXT_SETTLE_TIME	    = 'd',     	// ascii int &buf[2] - set settle time for LC transition from high to low
  HOST_TO_ZELDA_EXT_HOLDOFF_TIME	= 'h',     	// ascii int &buf[2] - set holdoff delay for state change from trigger
};

FRL_ZELDA_ENUM_CLASS usb_type FRL_ZELDA_ENUM_SIZE {
  FRL_USB_GEN_HID   = 0x01,     //
  FRL_USB_CDC       = 0x02,     //
};

FRL_ZELDA_ENUM_CLASS ReportType FRL_ZELDA_ENUM_SIZE
{
  GENERAL_INFO						= 0x01,		// Get board information
  GENERAL_UPDATE 					= 0x02,		// Original
};

typedef struct FRL_Template
{
	uint8_t             				_pre;
	FRL_ZELDA_ENUM_CLASS ReportType 	_ReportType;
	uint8_t								_buf[58];
	uint8_t								_count;
	uint8_t								_errors;
	uint8_t								_version;
	uint8_t             				_post;
} FRL_Template_t;
StructSizeCheck(FRL_Template_t, 64);

typedef struct FRL_Info
{
	uint8_t             				_pre;
	FRL_ZELDA_ENUM_CLASS ReportType 	_ReportType;
	uint16_t                            _encoder_value;
	uint8_t								_buf[56];
	uint8_t								_count;
	uint8_t								_errors;
	uint8_t								_version;
	uint8_t             				_post;
} FRL_Info_t;
StructSizeCheck(FRL_Info_t, 64);


typedef struct HID_Update
{
  uint8_t             				_pre;
  FRL_ZELDA_ENUM_CLASS ReportType 	_ReportType;
  uint16_t             				_DriverOutputState;
  uint16_t             				_RefreshRate;
  uint16_t             				_PosDriveTime;
  uint16_t             				_NegDriveTime;
  uint16_t             				_ClearTime;
  uint16_t             				_Voltage;
  uint16_t             				_VoltageRead;
  uint16_t             				_CurrentRead;
  uint16_t             				_TempRead;
  uint8_t             				_OnboardSupplyEnabled;
  uint8_t							_buf[39];
  uint8_t							_count;
  uint8_t							_errors;
  uint8_t							_version;
  uint8_t             				_post;
} HID_Update_t ;
StructSizeCheck(HID_Update_t, 64);


#ifdef __cplusplus

  #pragma pack(pop)
    };
  }

#else

  #pragma pack(pop)

#endif





















//////////////////////////////////////////////////////////////////////////////
//
//  NOTES
//
//  WITH HID PACKET SIZE 64
//
//  DEVICE SIDE
//		buffer[0] TO buffer[63] WILL BE SENT TO HOST
//
//  HOST SIDE
//		MUST READ 65 bytes. buffer[0] is report ID, buffer[1] TO buffer[64] contains DEVICE DATA
//
//
//
//////////////////////////////////////////////////////////////////////////////

#ifdef kfkjfkjkj

#ifdef __cplusplus
#define TBWIREFORMAT_ENUM_CLASS      enum class
#define TBWIREFORMAT_ENUM_SIZE       : uint8_t
#define TBWIREFORMAT_ENUM_TYPE
#define TBWIREFORMAT_STRUCT
#define TBWIREFORMAT_UNION
#else
#define TBWIREFORMAT_ENUM_CLASS      enum 
#define TBWIREFORMAT_ENUM_SIZE
#define TBWIREFORMAT_ENUM_TYPE       enum
#define TBWIREFORMAT_STRUCT          struct
#define TBWIREFORMAT_UNION           union
#pragma anon_unions
#endif



#ifdef __cplusplus    
namespace surreal
{
	class TBWireFormat
	{
	public:
#endif

#ifdef CPU_MKV58F1M0VLQ24   
#pragma push        
#pragma pack(1)
#else
#pragma pack(push, 1)
#endif
    
        //////////////////
	// BOARD TO HOST
        //////////////////
		TBWIREFORMAT_ENUM_CLASS B2HMsgType TBWIREFORMAT_ENUM_SIZE
		{
			kInfoM  = 0x00,     // Board type, serial number etc
			kPtpM   = 0x01,     // PTP status
			kFwM    = 0x02,     // FW version
			kImuM   = 0x10,     // IMU data
			kSyncM  = 0x20,     // Sync event
			kTrigM  = 0x30,     // trigger event (Not used)
			kProxyM = 0x40,	    // Proxy message from B2B UART
			kTempM  = 0x80,     // Temperature data
			kEpochM = 0xAA,     // Stream initialization info
			kAckM   = 0xFE      // Acknowledge message
		};

		TBWIREFORMAT_ENUM_CLASS PtpStatus TBWIREFORMAT_ENUM_SIZE
		{
			kPtpInit    = 0x00,     // initialising
			kPtpList    = 0x01,     // listening
			kPtpUncal   = 0x02,     // uncalibrated slave
			kPtpCal     = 0x03,     // calibrated
			kPtpErr     = 0xFF      // error
		};

		TBWIREFORMAT_ENUM_CLASS ImuSensorIdType TBWIREFORMAT_ENUM_SIZE
		{
			// note must fit into a 4 bits field
			kGyro   = 0x01,     // Gyroscope Data
			kAcc    = 0x02,     // Acceleromiter Data
			kMag    = 0x03,     // Magnetometer Data
			kTemp   = 0x04,     // Temperature Data
			kPress  = 0x05      // Pressure Data
		};
        
        TBWIREFORMAT_ENUM_CLASS ImuSource TBWIREFORMAT_ENUM_SIZE
		{
			kImuInvenSense = 0x01,	        // used in DeviceSource.id  (InvenSense)
			kImuBosch      = 0x02,	        // used in DeviceSource.id  (Bosch)
		};
        
		TBWIREFORMAT_ENUM_CLASS ProxyCmdType TBWIREFORMAT_ENUM_SIZE
		{
			kProxyMotorPCB 	= 0x01,		// proxy a message to Motor PCB 
		};
		
        struct SerialNum
		{
			uint8_t     msb;    // most significant bytes
			uint16_t    lss;    // least significant 4 bytes
		};
        
        struct TiaTime
		{
			uint16_t sms;  // seconds most significant 2 bytes
			uint32_t sls;  // seconds least significant 4 bytes
			uint32_t ns;
		};
        
        struct InfoData
		{
			uint8_t             protoVer;               // messaging protocol version number, currently 1.
			char                ver[3];                 // hw version string(e.g. k28 for KC2.8)
			TBWIREFORMAT_STRUCT SerialNum serial;		// 24 bits serial number
		};

		struct FwData
		{
			uint8_t major;  // fw major revision
			uint8_t minor;  // fw minor revision
			char sha[5];    // 5 bytes git sha
		};

		struct PtpData
		{
			uint8_t state;	// PtpStatus and the offset from master is saved in the TiaTime structure
		};

		union ImuPacket {
			struct a        // acc
			{
				int16_t x;
				int16_t y;
				int16_t z;
			}a_;
			struct g        // gyro
			{
				int16_t x;
				int16_t y;
				int16_t z;
			}g_;
			struct m        // mag
			{
				uint16_t x;
				uint16_t y;
				uint16_t z;
			}m_;
			struct t        // temp
			{
				uint16_t integer;
				uint8_t fract;
				uint8_t padding[3];
			};
			struct p        // press
			{
				uint8_t integer_;
				uint8_t fract_;
				uint8_t padding_[4];
			};
		};

		struct DeviceSource
		{
			uint8_t id : 4;      // IMU identifier (InvenSense or Bosch)
			uint8_t sensor : 4;  // sensor, example: Gyro, Temp (see ImuSensorIdType enum)
		};

		struct ImuData
		{
			TBWIREFORMAT_STRUCT DeviceSource    source;     // IMU ID + sensor ID
			TBWIREFORMAT_UNION  ImuPacket       val;        // bytes
		};

		struct SyncData
		{
			uint8_t     channel;    // channel # starts at 0x01
			uint32_t    count;      // # of syncs since last reset
			int16_t     extra;      // additional data
		};
        
        struct TriggerCountData
		{
			uint8_t     channel;    // channel # starts at 0x01
			uint32_t    count;      // trigger msg counter for this channel
			uint8_t     padding[2];
		};

		struct EpochData
		{
			uint32_t    count;      // epoch msg counter
			uint8_t     padding[3];
		};
        
        struct AckData
		{
			uint8_t     msgType;    // message acnowledged type
			uint8_t     msgSubType; // message acknowledged type (i.e. for control messages)
			uint32_t    errorNo;    // error condition 0x00 = OK
			uint8_t     padding;
		};
		
		struct ProxyData
		{
			TBWIREFORMAT_ENUM_TYPE ProxyCmdType cmd;	// control command see ControlCmdType enum
			uint8_t pkt[6];							// packet data (its really 32 TODO)
		};

		struct ThermoData
		{
			TBWIREFORMAT_STRUCT DeviceSource    source;     // I2C ID + sensor ID
			uint8_t temp[2];
			uint8_t padding_[4];			
		};
		
        // union with all the possible shapes the B2HData can take
		union B2HData {
			TBWIREFORMAT_STRUCT InfoData            info;
			TBWIREFORMAT_STRUCT FwData              fw;
			TBWIREFORMAT_STRUCT PtpData             ptp;
			TBWIREFORMAT_STRUCT ImuData             imu;
			TBWIREFORMAT_STRUCT SyncData            sync;
			TBWIREFORMAT_STRUCT TriggerCountData    trig;   // Not used yet
			TBWIREFORMAT_STRUCT EpochData           epoch;
			TBWIREFORMAT_STRUCT AckData             ack;
			TBWIREFORMAT_STRUCT ProxyData           prox;
			TBWIREFORMAT_STRUCT ThermoData			thermo;
		};

		// the uber fix length B2H message struct
		struct B2HMsg
		{
			union {
				struct
				{
					TBWIREFORMAT_ENUM_TYPE   B2HMsgType type;   // message type.
					TBWIREFORMAT_STRUCT      TiaTime    time;   // 6 + 4 bytes time format.
					TBWIREFORMAT_UNION       B2HData    data;
				};
				uint8_t bytes[18];					            // type specific payload.
			};
		};
        
        //////////////////
		// HOST TO BOARD
        //////////////////
		TBWIREFORMAT_ENUM_CLASS H2BMsgType TBWIREFORMAT_ENUM_SIZE
		{
			kRequest = 0x00,            // Request info from board
			kControl = 0x10,            // Control command to board
			kTrigger = 0x30,            // Config trigger events
			kProxy 	 = 0x40,			// Proxy message to B2B UART
		};

		TBWIREFORMAT_ENUM_CLASS RequestCmdType TBWIREFORMAT_ENUM_SIZE
		{
			kInfoR  = 0x00,     // requests an info packet (extra bytes ignored)
			kPtpR   = 0x01,     // requests a PTP status (extra bytes ignored)
			kFwR    = 0x02,     // requests a fw message (extra bytes ignored)
			kEpochR = 0x03,     // requests a Epoch message (extra bytes ignored)
		};

		TBWIREFORMAT_ENUM_CLASS ControlCmdType TBWIREFORMAT_ENUM_SIZE
		{
			kPower              = 0x01,	    // requests writing extra bytes to the power interface
			kSyncsReset         = 0x20,	    // requests a reset of all sync counters (extra bytes ignored)
            kEnableDisableImu   = 0x33,	    // command to enable/disable IMU (extra1 = 0 disables, extra1 = 1 enables, extra2 define which IMU)
            kDisableEnablePhy   = 0x35,	    // command to disable/enable ethernet PHY ~2 second power cycle
            kEnableDisableAck   = 0x40,	    // command to enable/disable ACK for all commands
			kEpochReset         = 0xAA,		// requests a reset of the Epoch (extra bytes ignored)
			kBoardReset         = 0xFF		// requests a timing board reset (extra bytes ignored)
		};
        
        TBWIREFORMAT_ENUM_CLASS TriggerCmdType TBWIREFORMAT_ENUM_SIZE
		{
			kTriggerConfig      = 0x01,     // trigger settings for channel, period, offset etc (see TriggerData)
			kTriggerStartStop   = 0x05,     // command start/stop of trigger counter (extra1 specifies channel, extra2 0x00 is stop, 0x01 is start, 0x00 acts on all channels)
            kTriggerResolution  = 0x08,	    // set trigger resolution in us (default is 5us) (uses extras)
            kTriggerReset       = 0x30,	    // reset of all trigger counters (extra bytes ignored)
            kTriggerCount       = 0x31,	    // command start/stop of trigger counter (extra1 specifies channel, extra2 0x00 is stop, 0x01 is start, 0x00 acts on all channels)
            kTriggerCountRead   = 0x33,	    // command read trigger counter (extra1 specifies channel)
            kTriggerClear       = 0x37	    // command clear all trigger configurations
		};
		
        struct RequestData
		{
			TBWIREFORMAT_ENUM_TYPE RequestCmdType cmd;	// request command see RequestCmdType enum
			uint8_t extra[2];							// extra data
            uint8_t padding[14];
		};
        
		struct ControlData
		{
			TBWIREFORMAT_ENUM_TYPE ControlCmdType cmd;	// control command see ControlCmdType enum
			uint8_t extra[2];							// extra data
            uint8_t padding[14];
		};

		struct TriggerData
		{
            TBWIREFORMAT_ENUM_TYPE TriggerCmdType cmd;	// request command see ControlCmdType enum
            union {
                struct {
                    uint8_t     channel;		// channel to config, channel number starts at  0x01
                    uint8_t     master;			// channel relative to which the offset is specified. if channel = master this assumed to be
                                                // the master channel
                    uint32_t    periodNs;		// trigger period in ns
                    uint32_t    offsetNs;		// offset from master in ns
                    uint32_t    activeTimeNs;   // active period of trigger pulse. if zeo equlaso to 50% ducty cycle
                    uint8_t     flags[2];       // bit 1 sets trigger as active low  ROB TO PROVIDE INFO
                };
                struct {
                    uint8_t extra[2];	        // extra data
                    uint8_t padding[14];
                };
            };
		};
    
		// union with all the possible shapes the H2BData can take
		union H2BData {
			TBWIREFORMAT_STRUCT ControlData ctrl;
			TBWIREFORMAT_STRUCT RequestData req;
			TBWIREFORMAT_STRUCT TriggerData trig;
			TBWIREFORMAT_STRUCT ProxyData prox;
		};

		// the uber fix length H2B message struct
		struct H2BMsg
		{
			union {
				struct
				{
					TBWIREFORMAT_ENUM_TYPE   H2BMsgType type;	// message type.
					TBWIREFORMAT_UNION       H2BData data;
				};
				uint8_t bytes[18];								// type specific payload.
			};
		};	

#ifdef CPU_MKV58F1M0VLQ24
#pragma pop
#else
#pragma pack(pop)
#endif

#ifdef __cplusplus    
	};
}
#endif

#endif

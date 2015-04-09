/**
 *******************************************************************************
 * \file    MasterRD.h
 *******************************************************************************
 * \brief    Headerdatei f黵 die DLL des RFID-Lesers CR500-USB. 
 * 
 * \version		1.0
 * \date		09.06.2008
 * \author		R.Zoss
 *
 * Copyright (C) 2008 Rico Zoss
 * 
 * This file is part of BEO-Timing Managementsoftware.
 *
 * BEO-Timing Managementsoftware is free software: you can redistribute 
 * it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * 
 * BEO-Timing Managementsoftware is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *  
 * You should have received a copy of the GNU General Public License
 * along with BEO-Timing Managementsoftware.  If not, see <http://www.gnu.org/licenses/>.
 * 
 *******************************************************************************
 */

#ifndef _EXPORT_FUNC_H_
#define _EXPORT_FUNC_H_

//return successful result
#define  LIB_SUCCESS      0  
//return failed result
#define  LIB_FAILED       1

#define MAX_RF_BUFFER     1024

/************************************************************/
/**************System Functions******************************/
/************************************************************/

/******** int WINAPI LIB_VER *************************
 *        @brief			Get DLL Version
 *        @fn				int  WINAPI  lib_ver(unsigned int *pVer)
 *        @param[out] nVer	DLL version
 *        @return			return 0 if successful
*********************************************************/
int (WINAPI* lib_ver)(unsigned int *nVer);


/******** int WINAPI RF_INIT_COM *************************/
//        Function:    Connect
//        Prototype:   int WINAPI  rf_init_com(int port, long baud)
//        Parameter:   port: [IN] serial port number
//                     baud: [IN] communication baud rate, 4800~115200 bps
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* rf_init_com)(int port,long baud);


/******** int WINAPI RF_INIT_DEVICE_NUMBER *************************/
//        Function:    Designate Device ID
//        Prototype:   int WINAPI rf_init_device_number)(unsigned short icdev)
//        Parameter:   icdev:    [IN]  Device ID
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* rf_init_device_number)(unsigned short icdev);


/******** int WINAPI RF_GET_DEVICE_NUMBER *************************/
//        Function:    Read Device ID
//        Prototype:   int WINAPI rf_get_device_number)(unsigned short *pIcdev)
//        Parameter:   pIcdev:    [OUT]  return to Device ID
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* rf_get_device_number)(unsigned short *Icdev);


/******** int WINAPI RF_GET_MODEL *************************/
//        Function:    Get Device Type
//        Prototype:   int WINAPI rf_get_model)(unsigned short icdev, 
//                                             unsigned char *pVersion,
//                                             unsigned char *pLen)
//        Parameter:   icdev:    [IN]  Device ID
//                     pVersion: [OUT] return information
//                     pLen:     [OUT] the length of the return information
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* rf_get_model)(unsigned short icdev,unsigned char *pVersion, unsigned char *pLen);




/******** int WINAPI RF_BEEP *************************/
//        Function:    beep
//        Prototype:   int WINAPI rf_beep(unsigned short icdev,
//                                        unsigned char msec)
//        Parameter:   icdev:    [IN]   Device ID
//                     msec:     [IN]   beep time, unit 10 MSEL
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* rf_beep)(unsigned short icdev,unsigned char msec);


/******** int WINAPI RF_INIT_TYPE *************************/
//        Function:    Set Reader contactless working mode
//        Prototype:   int WINAPI rf_init_type(unsigned short icdev,
//                                             unsigned char type)
//        Parameter:   icdev:    [IN]  Device ID
//                     type:     [IN]  reader working mode
//        Return:      return 0 if successful
//Explanation: this function is not effective to the readers only support single protocol.
//        type = 'A': set CR500 into ISO14443A mode
//        type = 'B': set TYPE_B mode
//        type = 'r': set AT88RF020 card mode
//        type = '1': set ISO15693 mode
/*********************************************************/
int (WINAPI* rf_init_type)(unsigned short icdev,unsigned char type);


/******** int WINAPI RF_ANTENNA_STA *************************/
//        Function:    Manage RF Transmittal
//        Prototype:   int WINAPI rf_antenna_sta(unsigned short icdev,
//                                               unsigned char model)
//        Parameter:   icdev:    [IN]  Device ID
//                     model:     [IN]  transmittal state
//        Return:      return 0 if successful
//Explanation: 
//        model = 0: turn off RF transmittal
//        model = 1: turn on RF transmittal
/*********************************************************/
int (WINAPI* rf_antenna_sta)(unsigned short icdev, unsigned char model);

/******** int WINAPI RF_LIGHT *************************/
//        Function:    Manage LED
//        Prototype:   int WINAPI rf_light(unsigned short icdev, 
//                                         unsigned char color)
//        Parameter:   icdev:    [IN]   Device ID
//                     color:    [IN]   0 : off
//                                      1 : red
//                                      2 : green
//                                      3 : yellow
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* rf_light)(unsigned short icdev,unsigned char color);

/******** int WINAPI RF_CLOSEPORT *************************/
//        Function:    Disconnect
//        Prototype:   int  WINAPI  rf_ClosePort()
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* rf_ClosePort)();


/*************** NO DOCUMENTATION *************************/
int (WINAPI* rf_get_snr)(unsigned short icdev,unsigned char *Snr);
int (WINAPI* rf_init_sam)(unsigned short icdev,unsigned char bound);
int (WINAPI* rf_sam_rst)(unsigned short icdev, unsigned char *pData,unsigned char *pMsgLg);
int (WINAPI* rf_sam_cos)(unsigned short icdev, unsigned char *command,unsigned char cmdLen ,unsigned char *pData,unsigned char* Length);
int (WINAPI* rf_GetErrorMessage)();

/************************************************************/
/******************DES FUNCTION******************************/
/************************************************************/

/******** int WINAPI DES_ENCRYPT *************************/
//        Function:    DES_Encrypt
//        Prototype:   int WINAPI des_encrypt(unsigned char *pSzOut, 
//                                            unsigned char *pSzIn,
//                                            unsigned int inlen,
//                                            unsigned char *pKey,
//                                            unsigned int keylen)
//        Parameter:   pSzOut:   [OUT]  deciphering, bytes equal to data
//                     pSzIn:    [IN]   data
//                     inlen:    [IN]   length of data, integer times of 8 bytes
//                     pKey:     [IN]   encrypt key
//                     keylen:   [IN]   length of key, 8 bytes for single DES, 
//                                      16 bytes for triple DES
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* des_encrypt)(unsigned char *szOut,unsigned char *szIn , unsigned int inlen,unsigned char *key,unsigned int keylen);


/******** int WINAPI DES_ENCRYPT *************************/
//        Function:    DES_Decrypt
//        Prototype:   int WINAPI des_decrypt(unsigned char *pSzOut, 
//                                            unsigned char *pSzIn,
//                                            unsigned int inlen,
//                                            unsigned char *pKey,
//                                            unsigned int keylen)
//        Parameter:   pSzOut:   [OUT]  data, bytes length equal to deciphering
//                     pSzIn:    [IN]   deciphering
//                     inlen:    [IN]   length of deciphering, integer times of 8 bytes
//                     pKey:     [IN]   encrypt key
//                     keylen:   [IN]   length of key, 8 bytes for single DES, 
//                                      16 bytes for triple DES
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* des_decrypt)(unsigned char *szOut,unsigned char *szIn , unsigned int inlen,unsigned char *key,unsigned int keylen);

/************************************************************/
/**************ISO14443A FUNCTION****************************/
/************************************************************/

/************************************************************/
/************** UltraLight ******************************/
/************************************************************/

/******** int WINAPI RF_REQUEST *************************/
//        Function:    ReqA
//        Prototype:   int WINAPI rf_request(unsigned short icdev,
//                                           unsigned char model,
//                                           unsigned short *pTagType)
//        Parameter:   icdev:    [IN]   Device ID
//                     model:    [IN]   REQ_MODE
//                     pTagType: [OUT]  return card style number
//        Return:      return 0 if successful
// Explanation:        mode = 0x26 REQ_STD
//                     mode = 0x52 REQ_ALL
/*********************************************************/
int (WINAPI* rf_request)(unsigned short icdev, unsigned char model, unsigned short *TagType);

/******** int WINAPI RF_UL_SELECT *************************/
//        Function:    Select UltraLight
//        Prototype:   int WINAPI rf_ul_select(unsigned short icdev,
//                                             unsigned char *pSnr,
//                                             unsigned char *pLen)
//        Parameter:   icdev:    [IN]   Device ID
//                     pSnr:     [OUT]  return card unique serial number
//                     pLen:     [OUT]  length of Snr
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* rf_ul_select)(unsigned short icdev,unsigned char *pSnr,unsigned char *pLen);

/******** int WINAPI RF_M1_READ *************************/
//        Function:    MilfareOne read
//        Prototype:   int WINAPI rf_M1_read(unsigned short icdev,
//                                           unsigned char block,
//                                           unsigned char *pData,
//                                           unsigned char *pLen)
//        Parameter:   icdev:    [IN]   Device ID
//                     block:    [IN]   block absolute address
//                     pData:    [OUT]  return date
//                     pLen:     [OUT]  length of return data
//        Return:      return 0 if successful
//Explanation: this function is applicable for Ultra_Light card. 
//             Every page of Ultra_Light card has 4bytes. Transfering this 
//             function every time, return 4 pages of date consectively.
/*********************************************************/
int (WINAPI* rf_M1_read)(unsigned short icdev, unsigned char block, unsigned char *pData,unsigned char *pLen);


/******** int WINAPI RF_UL_WRITE *************************/
//        Function:    Ultraight Write
//        Prototype:   int WINAPI rf_ul_write(unsigned short icdev,
//                                            unsigned char page,
//                                            unsigned char *pData)
//        Parameter:   icdev:    [IN]   Device ID
//                     page:     [IN]   UltraLight card page adress (0~0F)
//                     pData:    [IN]   written date, 4 bytes
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI*  rf_ul_write)
    (unsigned short icdev, unsigned char page, unsigned char *pData);

/******** int WINAPI RF_HALT *************************/
//        Function:    TYPE_A card HALT
//        Prototype:   int WINAPI rf_halt(unsigned short icdev)
//        Parameter:   icdev:    [IN]   Device ID
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI*  rf_halt)(unsigned short icdev);
	
/******************************************************/	
/********************* Milfare_Std ***********************/	
/******************************************************/		

/******** int WINAPI RF_REQUEST *************************/
//        Function:    ReqA
//        Prototype:   int WINAPI rf_request(unsigned short icdev,
//                                           unsigned char model,
//                                           unsigned short *pTagType)
//        Parameter:   icdev:    [IN]   Device ID
//                     model:    [IN]   REQ_MODE
//                     pTagType: [OUT]  return card style number
//        Return:      return 0 if successful
// Explanation:        mode = 0x26 REQ_STD
//                     mode = 0x52 REQ_ALL
/*********************************************************/
//int WINAPI rf_request(unsigned short icdev, 
//    unsigned char model, unsigned short *TagType);
//already definded above

/******** int WINAPI RF_ANTICOLL *************************/
//        Function:    Milfare card Anticollision
//        Prototype:   int WINAPI rf_anticoll(unsigned short icdev,
//                                            unsigned char bcnt,
//                                            unsigned char *pSnr,
//                                            unsigned char *pLen)
//        Parameter:   icdev:    [IN]   Device ID
//                     bcnt:     [IN]   must be 4
//                     pSnr:     [OUT]  return card unique serial number
//                     pLen:     [OUT]  length if Snr
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* rf_anticoll)(unsigned short icdev, unsigned char bcnt, unsigned char *pSnr,unsigned char* pRLength);


/******** int WINAPI RF_SELECT *************************/
//        Function:    Milfare card Selectting
//        Prototype:   int WINAPI rf_select(unsigned short icdev,
//                                          unsigned char *pSnr,
//                                          unsigned char snrLen,
//                                          unsigned char *pSize)
//        Parameter:   icdev:    [IN]   Device ID
//                     pSnr:     [IN]   return card unique serial number
//                     snrLen:   [IN]   length of Snr
//                     pSize:    [OUT]  return card capacity
//        Return:      return 0 if successful
//Explanation: card will be on active estate after receive this command, 
//             only one TYPE_A card on active estate at the same influence 
//             range at same time.
/*********************************************************/
int (WINAPI* rf_select)(unsigned short icdev,unsigned char *pSnr,unsigned char srcLen,unsigned char *Size);



int (WINAPI* rf_download_key)(WORD icdev, unsigned char mode, unsigned char *key);

/******** int WINAPI RF_M1_AUTHENTICATION2 *************************/
//        Function:    Milfare_Std Authentify
//        Prototype:   int WINAPI rf_authentication2(unsigned short icdev,
//                                                   unsigned char model,
//                                                   unsigned char block,
//                                                   unsigned char *pKey)
//        Parameter:   icdev:    [IN]   Device ID
//                     model:    [IN]   key validate mode   
//                     block:    [IN]   shoud validate the absolute module of the key
//                     pKey:     [IN]   key content, 6 bytes
//        Return:      return 0 if successful
//Explanation:         model = 0x60 Fwith KeyA
//                     model = 0x61 Fwith KeyB
/*********************************************************/
int (WINAPI* rf_M1_authentication1)(WORD icdev, unsigned char mode, unsigned char secnr);
int (WINAPI* rf_M1_authentication2)(unsigned short icdev,unsigned char model,unsigned char block,unsigned char *key);


/******** int WINAPI RF_M1_READ *************************/
//        Function:    MilfareOne read
//        Prototype:   int WINAPI rf_M1_read(unsigned short icdev,
//                                           unsigned char block,
//                                           unsigned char *pData,
//                                           unsigned char *pLen)
//        Parameter:   icdev:    [IN]   Device ID
//                     block:    [IN]   block absolute address
//                     pData:    [OUT]  return date
//                     pLen:     [OUT]  length of return data
//        Return:      return 0 if successful
//Explanation: this function is applicable for Ultra_Light card. 
//             Every page of Ultra_Light card has 4bytes. Transfering this 
//             function every time, return 4 pages of date consectively.
/*********************************************************/
//int (WINAPI* rf_M1_read)(unsigned short icdev, unsigned char block, unsigned char *pData,unsigned char *pLen);
//already definded above


/******** int WINAPI RF_M1_WRITE *************************/
//        Function:    Milfare_Std Write
//        Prototype:   int WINAPI rf_M1_write(unsigned short icdev,
//                                            unsigned char block,
//                                            unsigned char *pData)
//        Parameter:   icdev:    [IN]   Device ID
//                     block:    [IN]   block absolute address
//                     pData:    [OUT]  written date, 16 bytes
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* rf_M1_write)(unsigned short icdev, unsigned char block, unsigned char *data);


/******** int WINAPI RF_M1_INITVAL *************************/
//        Function:    Milfare_Std card Initialize Value
//        Prototype:   int WINAPI rf_M1_write(unsigned short icdev,
//                                            unsigned char block,
//                                            long value)
//        Parameter:   icdev:    [IN]   Device ID
//                     block:    [IN]   block absolute address
//                     value:    [IN]   initialize purse, HEX, low bytes in former
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* rf_M1_initval)(unsigned short icdev, unsigned char block, long value);


/******** int WINAPI RF_M1_READVAL *************************/
//        Function:    Milfare_Std card Read Vallue
//        Prototype:   int WINAPI rf_M1_readval(unsigned short icdev,
//                                              unsigned char block,
//                                              long *pValue)
//        Parameter:   icdev:    [IN]   Device ID
//                     block:    [IN]   block absolute address
//                     pValue:   [IN]   return value, HEX, low bytes in former
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* rf_M1_readval)(unsigned short icdev, unsigned char block,long* pValue);


/******** int WINAPI RF_M1_DECREMENT *************************/
//        Function:    Milfare purse decrement
//        Prototype:   int WINAPI rf_M1_decrement(unsigned short icdev,
//                                                unsigned char block,
//                                                long value)
//        Parameter:   icdev:    [IN]   Device ID
//                     block:    [IN]   block absolute address
//                     value:    [IN]   decrease value, HEX, low bytes in former
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* rf_M1_decrement)(unsigned short icdev, unsigned char block,long value);


/******** int WINAPI RF_M1_INCREMENT *************************/
//        Function:    Milfare purse increment
//        Prototype:   int WINAPI rf_M1_increment(unsigned short icdev,
//                                                unsigned char block,
//                                                long value)
//        Parameter:   icdev:    [IN]   Device ID
//                     block:    [IN]   block absolute address
//                     value:    [IN]   increase value, HEX, low bytes in former
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* rf_M1_increment)(unsigned short icdev, unsigned char block,long value);


/******** int WINAPI RF_M1_RESTORE *************************/
//        Function:    Milfare_Std Restore
//        Prototype:   int WINAPI rf_M1_restore(unsigned short icdev,
//                                              unsigned char block)
//        Parameter:   icdev:    [IN]   Device ID
//                     block:    [IN]   block absolute address
//        Return:      return 0 if successful
/*********************************************************/
int (WINAPI* rf_M1_restore)(unsigned short icdev, unsigned char block);


/******** int WINAPI RF_M1_TRANSFER *************************/
//        Function:    Milfare_Std Transfer
//        Prototype:   int WINAPI rf_M1_tranfer(unsigned short icdev,
//                                              unsigned char block)
//        Parameter:   icdev:    [IN]   Device ID
//                     block:    [IN]   block absolute address
//        Return:      return 0 if successful
//Explanation: this function only be transferred after increment, decrement
//             and restore command
/*********************************************************/
int (WINAPI* rf_M1_transfer)(unsigned short icdev, unsigned char block);


/******** int WINAPI RF_M1_HALT *************************/
//        Function:    Milfare Halt
//        Prototype:   int WINAPI rf_halt(unsigned short icdev)
//        Parameter:   icdev:    [IN]   Device ID
//        Return:      return 0 if successful
//Explanation: card exit active estate after receive this command
/*********************************************************/
//int (WINAPI*  rf_halt)(unsigned short icdev);

/**************************************************************/
/**************************ISOP14443B***************************/
/**************************************************************/

/******** 功能：复位符合ISO14443-A 标准的CPU 卡 **********/
//  参数：icdev： 通讯设备标识符
//        model:  寻卡方式
//        pDate：返回的复位信息内容
//        pMsgLg：返回复位信息长度
//  返回：成功则返回0
//  说明：
/*********************************************************/
int (WINAPI* rf_typea_rst)(unsigned short icdev,unsigned char model,unsigned char *pData,unsigned char *pMsgLg);
/*例：int status
      unsigned short icdev
      unsigned char pData[MAX_RF_BUFFER];
      unsigned char len;
      status = rf_typea_rst(icdev,0,pData,&len);      
*/


/******** 功能：向符合ISO14443-4标准的CPU卡发送COS 命令***/
//  参数：icdev：  通讯设备标识符
//        command：cos 命令
//        cmdLen:  cos 命令长度
//        pDate： 卡片返回的数据，含SW1、SW2
//        pMsgLg： 返回数据长度
//  返回：成功则返回0
//  说明：
/*********************************************************/
int (WINAPI* rf_cos_command)(unsigned short icdev,unsigned char *command,unsigned char cmdLen,unsigned char *pData,unsigned char* pMsgLg);
/*例：int status
      unsigned short icdev
      unsigned char* cmd;
      unsigned char pData[MAX_RF_BUFFER];
      unsigned char len;
      status = rf_typea_cos(icdev,cmd,sizeof(cmd),pData,&len);      
*/


/******** 功能：激活符合ISO14443 TYPE_B 标准的卡 *********/
//  参数：icdev： 通讯设备标识符
//        model： 寻卡方式0＝REQB,1=WUPB
//        pDate：卡片返回的数据
//        pMsgLg：返回数据的长度
//  返回：成功则返回0
//  说明：
/*********************************************************/
int (WINAPI* rf_atqb)(unsigned short icdev,unsigned char model,unsigned char *pData,unsigned char *pMsgLg);
/*例：int status
      int icdev
      unsigned char msglg
      unsigned char pDate[MAX_RF_BUFFER];
      status = rf_atqb(icdev,0,pDate,&msglg);      
*/

/*********  功能：激活已寻到的符合ISO14443-B 标准的卡 ************/
//  参数：icdev：通讯设备标识符
//        PUPI ： 卡片唯一标识符
//        CID  ： 指定该卡片使用的逻辑地址,取值0～14 且小于slotmax
//  返回：成功则返回0
/*****************************************************************/
int (WINAPI* rf_attrib)(WORD icdev, unsigned long PUPI, unsigned char CID);

/*********  功能：向符合ISO14443-B 标准的CPU 卡发送COS 命令 ******/
//  参数：icdev：通讯设备标识符
//        CID  ：卡片逻辑地址
//        command：cos 命令
//        MsgLg：返回数据长度
//        Date： 卡片返回的数据，含SW1、SW2
//  返回：成功则返回0
/*****************************************************************/

int (WINAPI* rf_typeb_cos)(WORD icdev, unsigned char CID,unsigned char *command, unsigned char cmdLen,unsigned char *pData,unsigned char *pMsgLg);
/*
例：int status
int icdev
unsigned char *command;
unsigned char msglg;
unsigned char pData[MAX_RF_BUFFER];
status = rf_typeb_cos(icdev,0,command,sizeof(command),pData,&msglg);
*/
/******** 功能：命令一选中的TYPE_B卡进入HALT 状态*********/
//  参数：icdev：通讯设备标识符
//        PUPI： 卡片唯一标识符
//  返回：成功则返回0
/*********************************************************/
int (WINAPI* rf_hltb)(unsigned short icdev,unsigned long PUPI);
//??

/******** 功能：验证AT88RF020 卡密码 *********************/
//  参数：icdev：通讯设备标识符
//        key：  密码，8 字节
//  返回：成功则返回0
/*********************************************************/
int (WINAPI* rf_at020_check)(unsigned short icdev, unsigned char *key);


//******* 功能：读AT88RF020 卡一页数据 *******************/
//  参数：icdev： 通讯设备标识符
//        page：  页地址，（0～31）
//        pDate：返回的数据
//        pMsgLen:返回数据的长度
//  返回：成功则返回0
//  说明：
/*********************************************************/
int (WINAPI* rf_at020_read)(unsigned short icdev, unsigned char page, unsigned char *pData,unsigned char* pMsgLen); 
/*
例：int status
    int icdev
    unsigned char pData[MAX_RF_BUFFER];
    unsigned char len;
    status = rf_at020_read(icdev,0,pData,&len);    
*/


/******** 功能：写AT88RF020 卡一页数据 *******************/
//  参数：icdev：通讯设备标识符
//        page： 页地址，（0～31）
//        Date： 要写入的数据，8 字节
//  返回：成功则返回0
/*********************************************************/
int (WINAPI* rf_at020_write)(unsigned short icdev, unsigned char page, unsigned char *data);
 

/******** 功能：LOCK AT88RF020卡**************************/
//  参数：icdev：通讯设备标识符
//        date： 数据，4 字节
//  返回：成功则返回0
/*********************************************************/
int (WINAPI* rf_at020_lock)(unsigned short icdev,unsigned char *data);


/******** 功能：AT88RF020卡计数函数 **********************/
//  参数：icdev：通讯设备标识符
//        date： 数据，6 字节
//  返回：成功则返回0
/*********************************************************/
int (WINAPI* rf_at020_count)(unsigned short icdev,unsigned char *data);


/******** 功能：命令AT88RF020 卡进入HALT 状态 ************/
//  参数：icdev：通讯设备标识符
//  返回：成功则返回0
/*********************************************************/
int (WINAPI* rf_at020_deselect)(unsigned short icdev);


/******** 功能：控制灯的颜色 *****************************/
//  参数：icdev：通讯设备标识符
//        color: 0 ,熄灯
//               1 ,红灯
//               2 ,绿灯
//               3 ,黄灯
//  返回：成功返回0
/*********************************************************/



#endif

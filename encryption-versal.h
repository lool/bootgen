/******************************************************************************
* Copyright 2015-2020 Xilinx, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
******************************************************************************/

#pragma once
#ifndef _ENCRYPTION_VERSAL_CONTEXT_
#define _ENCRYPTION_VERSAL_CONTEXT_

/*
-------------------------------------------------------------------------------
***********************************************   H E A D E R   F I L E S   ***
-------------------------------------------------------------------------------
*/
#include <string>
#include "bootgenenum.h"
#include "options.h"
#include <stdint.h>
#include <sstream>

/* Forward Class References */
class PartitionHeader;
class Options;
class DataMover;

/*
-------------------------------------------------------------------------------
*********************************************************   C L A S S E S   ***
-------------------------------------------------------------------------------
*/
/******************************************************************************/
class VersalEncryptionContext : public EncryptionContext
{
public:
    VersalEncryptionContext() 
    {
        LOG_ERROR("Encryption is not supported for Versal ACAP in this version of Bootgen. \n\
           Please use Bootgen from Xilinx install");
    }
    VersalEncryptionContext(const EncryptionContext * other)
    {
        LOG_ERROR("Encryption is not supported for Versal ACAP in this version of Bootgen. \n\
        Please use Bootgen from Xilinx install");
    }
    ~VersalEncryptionContext() { }

    Encryption::Type Type() { return Encryption::AES; }

    std::string ConvertKeyIvToString(uint8_t *keyIv, uint8_t size) { return ""; }
    void Process(BootImage& bi, PartitionHeader* partition) { }
    void Process(BootImage& bi) { }
    void SetAesSeedString(const std::string & key) { }
    void SetAesSeed(const uint8_t * key) { }
    const uint32_t* GetAesSeed(void) { return NULL; }
    void SetAesLabelString(const std::string & key) { }
    void SetAesLabel(const uint8_t * key, int bytes) { }
    const uint8_t* GetAesLabel(void) { return NULL; }
    void SetAesContextString(const std::string & key) { }
    void GenerateAesSeed(void) { }
    void SetAesContext(const uint8_t * key, int bytes) { }
    const uint8_t* GetAesContext(void) { return NULL; }
    void GenerateAesKey(void) { }
    void WriteEncryptionKeyFile(const std::string& baseFileName, bool useOptionalKey){ }
    void WriteEncryptionKeyFilefromKDF(const std::string& baseFileName, bool useOptionalKey, uint32_t blocks) { }
    void ReadEncryptionKeyFile(const std::string& keyFileName) { }
    void GenerateEncryptionKeyFile(const std::string& baseFileName, Options& options) { }
    void EncryptKeys(const uint8_t* inputData, uint32_t inputDataByteLength, uint8_t* encryptedData) { }
    void SetAesKey(const uint8_t* binarykey) { }
    const uint32_t* GetAesKey(void) { return NULL; }
    void SetIv(const uint8_t* iv) { }
    void SetIvString(const std::string& IV) { }
    void GenerateIv(void) { }
    const uint32_t* GetIv(void) { return NULL; }
    void PackNextEncryptionKey(uint8_t* aesKeyNext, int aeskeyPtr) { }
    void PackNextIv(uint8_t * aesIvNext, int aesIvPtr) { }
    void GetNextKey(uint8_t* keyNext, int ptr) { }
    void GetNextIv(uint8_t* keyNext, int ptr) { }
    void GenerateRemainingKeys(Options& options) { }

    std::vector<std::string> aesKeyVec;
    std::vector<std::string> aesIvVec;

private:
    bool isBootloader;
    bool isPmcData;
    bool aesSeedexits;

    void ChunkifyAndEncrypt(Options& options, const uint8_t *inBuf, uint32_t inLen, uint8_t* outBuf, uint32_t& outLen) { }
    void GetEncryptionKeys(Options& options, uint8_t* aesKey, uint8_t* aesOptKey, uint8_t* aesIV) { }

    void AesGcm256Encrypt(unsigned char* gcm_pt, int pt_len, unsigned char* gcm_key, unsigned char* gcm_iv, unsigned char* gcm_aad, int aad_len,
        unsigned char* gcm_ct, int& ct_len, unsigned char* gcm_tag) { }
    void AesGcm256Decrypt(unsigned char* gcm_pt, int& pt_len, unsigned char* gcm_key, unsigned char* gcm_iv, unsigned char* gcm_aad, int aad_len,
        unsigned char* gcm_ct, int ct_len, unsigned char* gcm_tag) { }

protected:
    AesGcmEncryptionContext* encryptionAlgorithm;
};
#endif

#pragma once
/*****************************************************************************
 * 
 * Copyright 2016 Varol Okan. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 ****************************************************************************/

#include <stdint.h>

// MPEG-4 constants
namespace constants
{

static const char *TRAK_TYPE_VIDE = "vide";

// Leaf types.
static const char *TAG_STCO = "stco";
static const char *TAG_CO64 = "co64";
static const char *TAG_FREE = "free";
static const char *TAG_MDAT = "mdat";
static const char *TAG_XML  = "xml ";
static const char *TAG_HDLR = "hdlr";
static const char *TAG_FTYP = "ftyp";
static const char *TAG_ESDS = "esds";
static const char *TAG_SOUN = "soun";
static const char *TAG_SA3D = "SA3D";

// Container types.
static const char *TAG_MOOV = "moov";
static const char *TAG_EDTS = "edts";
static const char *TAG_TRAK = "trak";
static const char *TAG_MDIA = "mdia";
static const char *TAG_MINF = "minf";
static const char *TAG_DINF = "dinf";
static const char *TAG_STBL = "stbl";
static const char *TAG_MVEX = "mvex";
static const char *TAG_MOOF = "moof";
static const char *TAG_TRAF = "traf";
static const char *TAG_MFRA = "mfra";
static const char *TAG_META = "meta";
static const char *TAG_UDTA = "udta";
static const char *TAG_IPRO = "ipro";
static const char *TAG_SINF = "sinf";
static const char *TAG_STSD = "stsd";

static const char *TAG_UUID = "uuid";
static const char *TAG_WAVE = "wave";

static const char *TAG_DREF = "dref";

// Sound sample descriptions.
static const char *TAG_NONE = "NONE";
static const char *TAG_RAW_ = "raw ";
static const char *TAG_TWOS = "twos";
static const char *TAG_SOWT = "sowt";
static const char *TAG_FL32 = "fl32";
static const char *TAG_FL64 = "fl64";
static const char *TAG_IN24 = "in24";
static const char *TAG_IN32 = "in32";
static const char *TAG_ULAW = "ulaw";
static const char *TAG_ALAW = "alaw";
static const char *TAG_LPCM = "lpcm";
static const char *TAG_MP4A = "mp4a";

static const char * LEAF_LIST[] = {
	TAG_STCO,
	TAG_CO64,
	TAG_FREE,
	TAG_MDAT,
	TAG_XML,
	TAG_HDLR,
	TAG_FTYP,
	TAG_ESDS,
	TAG_SOUN,
	TAG_SA3D
};

static const char * PADDING_LIST[] = {
	TAG_STSD,
	TAG_DREF
};

static const char * SOUND_SAMPLE_DESCRIPTIONS[] = {
    TAG_NONE,
    TAG_RAW_,
    TAG_TWOS,
    TAG_SOWT,
    TAG_FL32,
    TAG_FL64,
    TAG_IN24,
    TAG_IN32,
    TAG_ULAW,
    TAG_ALAW,
    TAG_LPCM,
    TAG_MP4A
};

static const char * CONTAINERS_LIST[] = {
    TAG_MDIA,
    TAG_MINF,
    TAG_MOOV,
    TAG_STBL,
    TAG_STSD,
    TAG_TRAK,
    TAG_UDTA,
    TAG_WAVE,
	TAG_EDTS,
	TAG_DINF,
	TAG_MVEX,
	TAG_MOOF,
	TAG_TRAF,
	TAG_MFRA,
	TAG_IPRO,
	TAG_SINF,
	TAG_DREF,
	TAG_META,

    TAG_NONE,
    TAG_RAW_,
    TAG_TWOS,
    TAG_SOWT,
    TAG_FL32,
    TAG_FL64,
    TAG_IN24,
    TAG_IN32,
    TAG_ULAW,
    TAG_ALAW,
    TAG_LPCM,
    TAG_MP4A
};

  enum Type {
    Box = 0,
    Container,
    ContainerLeaf,
    None
  };

  inline bool IS_LEAF(const char * name)
  {
	  int32_t iArrSize = (int32_t)(sizeof(constants::LEAF_LIST) / sizeof(constants::LEAF_LIST[0]));
	  for (int32_t i = 0; i < iArrSize; i++) {
		  if (memcmp(name, constants::LEAF_LIST[i], 4) == 0) {
			  return true;
		  }
	  }
	  return false;
  }
  inline bool IS_PADDING_LIST(const char * name)
  {
	  int32_t iArrSize = (int32_t)(sizeof(constants::PADDING_LIST) / sizeof(constants::PADDING_LIST[0]));
	  for (int32_t i = 0; i < iArrSize; i++) {
		  if (memcmp(name, constants::PADDING_LIST[i], 4) == 0) {
			  return true;
		  }
	  }
	  return false;
  }

  inline bool IS_SOUND_SAMPLE(const char * name)
  {
	  int32_t iArrSize = (int32_t)(sizeof(constants::SOUND_SAMPLE_DESCRIPTIONS) / sizeof(constants::SOUND_SAMPLE_DESCRIPTIONS[0]));
	  for (int32_t i = 0; i < iArrSize; i++) {
		  if (memcmp(name, constants::SOUND_SAMPLE_DESCRIPTIONS[i], 4) == 0) {
			  return true;
		  }
	  }
	  return false;
  }

  inline bool IS_CONTAINERS(const char * name)
  {
	  int32_t iArrSize = (int32_t)(sizeof(constants::CONTAINERS_LIST) / sizeof(constants::CONTAINERS_LIST[0]));
	  for (int32_t i = 0; i < iArrSize; i++) {
		  if (memcmp(name, constants::CONTAINERS_LIST[i], 4) == 0) {
			  return true;
		  }
	  }
	  return false;
  }

  static const char * TypeString[] = {
	  "Box",
	  "Container",
	  "ContainerLeaf",
	  "None"
  };

  inline const char * TypeName(Type t)
  {
	  return TypeString[t];
  }
};  // End of namespace constants


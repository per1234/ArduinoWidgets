#include "AWFont-ChicagoDigit-36.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kRangeArray_ChicagoFLF36 [2] = {
 0x30,  0x39
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint8_t kAdvancementArray_ChicagoFLF36 [10] = {
  24, // Character '0', entry 0
  24, // Character '1', entry 1
  24, // Character '2', entry 2
  24, // Character '3', entry 3
  24, // Character '4', entry 4
  24, // Character '5', entry 5
  24, // Character '6', entry 6
  24, // Character '7', entry 7
  24, // Character '8', entry 8
  24, // Character '9', entry 9
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint8_t kHorizontalSegmentArray_ChicagoFLF36 [111] = {
 0x7, 0x9C, // Index 0
 0x9F, 0x4, // Index 2
 0x2F, 0xE, // Index 4
 0x9, 0x8C, // Index 6
 0x3F, 0xA, // Index 8
 0x1F, 0xF, 0x2, // Index 10
 0x8E, // Index 13
 0x1B, 0x6A, // Index 14
 0x7E, // Index 16
 0xBE, // Index 17
 0x4A, // Index 18
 0x5B, 0x2C, // Index 19
 0x17, 0x8A, // Index 21
 0x1A, // Index 23
 0x4F, 0xA, // Index 24
 0x4E, // Index 26
 0x3A, // Index 27
 0xD, 0x6C, // Index 28
 0xAE, // Index 30
 0xD, 0x6A, // Index 31
 0xC8, // Index 33
 0x3E, // Index 34
 0x5A, // Index 35
 0x3F, 0x2, // Index 36
 0x3F, 0xF, 0x2, // Index 38
 0xCC, // Index 41
 0x4F, 0x2, // Index 42
 0x4F, 0x8, // Index 44
 0xF, 0xF, 0x8, // Index 46
 0x4B, 0x3C, // Index 49
 0xAA, // Index 51
 0xCA, // Index 52
 0xBC, // Index 53
 0x33, 0x2C, // Index 54
 0x9A, // Index 56
 0x1F, 0xF, 0x6, // Index 57
 0x4F, 0xC, // Index 60
 0x4F, 0x6, // Index 62
 0xF, 0xF, 0xE, // Index 64
 0xBA, // Index 67
 0x2B, 0x5C, // Index 68
 0x2F, 0xF, 0x4, // Index 70
 0xB, 0x7C, // Index 73
 0x6F, 0x4, // Index 75
 0x3F, 0x4, // Index 77
 0x35, 0x1C, // Index 79
 0x1F, 0xF, 0x4, // Index 81
 0xAF, 0x2, // Index 84
 0x6E, // Index 86
 0x7F, 0x2, // Index 87
 0xF, 0xF, 0x4, // Index 89
 0x3B, 0x4C, // Index 92
 0x9E, // Index 94
 0x2A, // Index 95
 0x7F, 0x8, // Index 96
 0x3F, 0x8, // Index 98
 0x8F, 0x6, // Index 100
 0xAC, // Index 102
 0x5E, // Index 103
 0xF, 0xF, 0x6, // Index 104
 0x6B, 0x1C, // Index 107
 0x1B, 0x6C, // Index 109
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint8_t kCharacterSegmentIndexArray8_ChicagoFLF36 [270] = {
 62, 4, 81, 14, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 14, 81, 4, 62, // Character '0', entry 0
 103, 42, 77, 79, 54, 54, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, // Character '1', entry 1
 62, 4, 81, 21, 0, 0, 41, 41, 41, 41, 41, 53, 102, 1, 7, 74, 29, 69, 93, 50, 20, 80, 61, 61, 46, 46, 46, // Character '2', entry 2
 46, 46, 46, 30, 94, 13, 16, 103, 26, 62, 24, 60, 41, 41, 41, 41, 41, 41, 41, 41, 41, 0, 0, 21, 81, 4, 62, // Character '3', entry 3
 17, 84, 2, 100, 96, 107, 19, 49, 92, 68, 109, 73, 6, 0, 0, 64, 64, 64, 41, 41, 41, 41, 41, 41, 41, 41, 41, // Character '4', entry 4
 46, 46, 46, 61, 61, 61, 61, 61, 61, 65, 89, 104, 52, 41, 41, 41, 41, 41, 41, 41, 41, 0, 0, 21, 81, 4, 62, // Character '5', entry 5
 13, 87, 75, 35, 18, 27, 95, 23, 61, 65, 89, 104, 31, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 14, 81, 4, 62, // Character '6', entry 6
 46, 46, 46, 41, 41, 41, 41, 41, 41, 41, 41, 53, 102, 94, 13, 16, 86, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, // Character '7', entry 7
 62, 4, 81, 14, 28, 28, 28, 28, 28, 28, 28, 14, 81, 8, 10, 14, 28, 28, 28, 28, 28, 28, 28, 14, 81, 4, 98, // Character '8', entry 8
 44, 4, 81, 14, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 57, 70, 38, 52, 33, 67, 51, 56, 22, 77, 36, 34, // Character '9', entry 9
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const AWFontInternalDefinition ChicagoDigit36 = {
  36, // Font size
  27, // Ascender
  1, // Descender
  1, // Range Count
  24, // Maximum Advancement
  3, // Empty Left Column Count
  21, // Column Count
  kRangeArray_ChicagoFLF36,
  kAdvancementArray_ChicagoFLF36,
  kHorizontalSegmentArray_ChicagoFLF36,
  kCharacterSegmentIndexArray8_ChicagoFLF36,
  NULL,
  "ChicagoFLF" // Font Name
} ; // 399 bytes

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————


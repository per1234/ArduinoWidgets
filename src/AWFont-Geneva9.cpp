#include "AWFont-Geneva9.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kRangeArray_Geneva9 [14] = {
 0x20,  0x7E,
 0xB5,  0xB5,
 0xC0,  0xC1,
 0xC6,  0xCB,
 0xE0,  0xEB,
 0xF9,  0xFC,
 0x152,  0x153
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint8_t kAdvancementArray_Geneva9 [122] = {
  3, // Character ' ', entry 0
  3, // Character '!', entry 1
  4, // Character '"', entry 2
  6, // Character '#', entry 3
  6, // Character '$', entry 4
  8, // Character '%', entry 5
  7, // Character '&', entry 6
  3, // Character ''', entry 7
  4, // Character '(', entry 8
  4, // Character ')', entry 9
  5, // Character '*', entry 10
  6, // Character '+', entry 11
  3, // Character ',', entry 12
  3, // Character '-', entry 13
  3, // Character '.', entry 14
  5, // Character '/', entry 15
  6, // Character '0', entry 16
  6, // Character '1', entry 17
  6, // Character '2', entry 18
  6, // Character '3', entry 19
  6, // Character '4', entry 20
  6, // Character '5', entry 21
  6, // Character '6', entry 22
  6, // Character '7', entry 23
  6, // Character '8', entry 24
  6, // Character '9', entry 25
  3, // Character ':', entry 26
  3, // Character ';', entry 27
  6, // Character '<', entry 28
  6, // Character '=', entry 29
  6, // Character '>', entry 30
  5, // Character '?', entry 31
  8, // Character '@', entry 32
  7, // Character 'A', entry 33
  6, // Character 'B', entry 34
  6, // Character 'C', entry 35
  6, // Character 'D', entry 36
  5, // Character 'E', entry 37
  5, // Character 'F', entry 38
  6, // Character 'G', entry 39
  6, // Character 'H', entry 40
  2, // Character 'I', entry 41
  4, // Character 'J', entry 42
  6, // Character 'K', entry 43
  5, // Character 'L', entry 44
  7, // Character 'M', entry 45
  6, // Character 'N', entry 46
  7, // Character 'O', entry 47
  5, // Character 'P', entry 48
  7, // Character 'Q', entry 49
  5, // Character 'R', entry 50
  6, // Character 'S', entry 51
  6, // Character 'T', entry 52
  6, // Character 'U', entry 53
  7, // Character 'V', entry 54
  9, // Character 'W', entry 55
  5, // Character 'X', entry 56
  5, // Character 'Y', entry 57
  5, // Character 'Z', entry 58
  4, // Character '[', entry 59
  5, // Character '\', entry 60
  4, // Character ']', entry 61
  6, // Character '^', entry 62
  6, // Character '_', entry 63
  5, // Character '`', entry 64
  5, // Character 'a', entry 65
  5, // Character 'b', entry 66
  5, // Character 'c', entry 67
  5, // Character 'd', entry 68
  5, // Character 'e', entry 69
  4, // Character 'f', entry 70
  5, // Character 'g', entry 71
  5, // Character 'h', entry 72
  3, // Character 'i', entry 73
  3, // Character 'j', entry 74
  5, // Character 'k', entry 75
  3, // Character 'l', entry 76
  8, // Character 'm', entry 77
  5, // Character 'n', entry 78
  5, // Character 'o', entry 79
  5, // Character 'p', entry 80
  5, // Character 'q', entry 81
  3, // Character 'r', entry 82
  5, // Character 's', entry 83
  4, // Character 't', entry 84
  5, // Character 'u', entry 85
  5, // Character 'v', entry 86
  7, // Character 'w', entry 87
  5, // Character 'x', entry 88
  5, // Character 'y', entry 89
  5, // Character 'z', entry 90
  4, // Character '{', entry 91
  2, // Character '|', entry 92
  4, // Character '}', entry 93
  6, // Character '~', entry 94
  5, // Character 'µ', entry 95
  7, // Character 'À', entry 96
  7, // Character 'Á', entry 97
  9, // Character 'Æ', entry 98
  6, // Character 'Ç', entry 99
  5, // Character 'È', entry 100
  5, // Character 'É', entry 101
  5, // Character 'Ê', entry 102
  5, // Character 'Ë', entry 103
  5, // Character 'à', entry 104
  5, // Character 'á', entry 105
  5, // Character 'â', entry 106
  5, // Character 'ã', entry 107
  5, // Character 'ä', entry 108
  5, // Character 'å', entry 109
  8, // Character 'æ', entry 110
  5, // Character 'ç', entry 111
  5, // Character 'è', entry 112
  5, // Character 'é', entry 113
  5, // Character 'ê', entry 114
  5, // Character 'ë', entry 115
  5, // Character 'ù', entry 116
  5, // Character 'ú', entry 117
  5, // Character 'û', entry 118
  5, // Character 'ü', entry 119
  10, // Character 'Œ', entry 120
  9, // Character 'œ', entry 121
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint8_t kHorizontalSegmentArray_Geneva9 [81] = {
 0x33, 0x12, // Index 0
 0x18, // Index 2
 0xA, // Index 3
 0x15, 0x14, // Index 4
 0x43, 0x22, // Index 6
 0x23, 0x13, 0x22, // Index 8
 0x17, 0x12, // Index 11
 0x1E, // Index 13
 0x6, // Index 14
 0x0, // Index 15
 0x3, 0x13, 0x12, // Index 16
 0x13, 0x34, // Index 19
 0x3A, // Index 21
 0x7, 0x14, // Index 22
 0x3, 0x52, // Index 24
 0x3, 0x24, // Index 26
 0x5, 0x34, // Index 28
 0x3, 0x36, // Index 30
 0x3, 0x12, // Index 32
 0x15, 0x12, // Index 34
 0x3, 0x13, 0x13, 0x12, // Index 36
 0x2, // Index 40
 0x3, 0x23, 0x22, // Index 41
 0x3, 0x32, // Index 44
 0x15, 0x16, // Index 46
 0x8, // Index 48
 0x15, 0x32, // Index 49
 0x3, 0x14, // Index 51
 0x5, 0x22, // Index 53
 0x1A, // Index 55
 0x25, 0x14, // Index 56
 0x2C, // Index 58
 0x1C, // Index 59
 0xC, // Index 60
 0x42, // Index 61
 0x3, 0x26, // Index 62
 0x3, 0x22, // Index 64
 0x4, // Index 66
 0x3, 0x38, // Index 67
 0x13, 0x32, // Index 69
 0x3, 0x28, // Index 71
 0x35, 0x22, // Index 73
 0x3, 0x25, 0x12, // Index 75
 0x3, 0x23, 0x12, // Index 78
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint8_t kCharacterSegmentIndexArray8_Geneva9 [1342] = {
 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, // Character ' ', entry 0
 15, 15, 1, 1, 1, 1, 1, 15, 1, 15, 15, // Character '!', entry 1
 15, 15, 17, 17, 15, 15, 15, 15, 15, 15, 15, // Character '"', entry 2
 15, 0, 55, 79, 55, 17, 15, 15, 15, 15, 15, // Character '#', entry 3
 15, 7, 47, 16, 32, 47, 79, 16, 47, 7, 15, // Character '$', entry 4
 15, 15, 13, 41, 78, 46, 73, 8, 19, 15, 15, // Character '%', entry 5
 15, 27, 9, 17, 7, 37, 44, 78, 49, 15, 15, // Character '&', entry 6
 15, 15, 1, 1, 15, 15, 15, 15, 15, 15, 15, // Character ''', entry 7
 15, 7, 1, 40, 40, 40, 40, 40, 1, 7, 15, // Character '(', entry 8
 15, 40, 1, 7, 7, 7, 7, 7, 1, 40, 15, // Character ')', entry 9
 15, 15, 45, 37, 63, 79, 69, 15, 15, 15, 15, // Character '*', entry 10
 15, 15, 15, 7, 7, 3, 7, 7, 15, 15, 15, // Character '+', entry 11
 15, 15, 15, 15, 15, 15, 15, 15, 7, 7, 1, // Character ',', entry 12
 15, 15, 15, 15, 15, 48, 15, 15, 15, 15, 15, // Character '-', entry 13
 15, 15, 15, 15, 15, 15, 15, 15, 1, 15, 15, // Character '.', entry 14
 15, 61, 61, 45, 45, 7, 7, 1, 1, 15, 15, // Character '/', entry 15
 15, 15, 47, 44, 44, 44, 44, 44, 47, 15, 15, // Character '0', entry 16
 15, 15, 7, 5, 7, 7, 7, 7, 7, 15, 15, // Character '1', entry 17
 15, 15, 47, 44, 61, 45, 7, 1, 3, 15, 15, // Character '2', entry 18
 15, 15, 3, 45, 7, 47, 61, 44, 47, 15, 15, // Character '3', entry 19
 15, 15, 45, 27, 17, 64, 3, 45, 45, 15, 15, // Character '4', entry 20
 15, 15, 3, 40, 48, 61, 61, 44, 47, 15, 15, // Character '5', entry 21
 15, 15, 27, 1, 40, 48, 44, 44, 47, 15, 15, // Character '6', entry 22
 15, 15, 3, 61, 45, 45, 7, 7, 7, 15, 15, // Character '7', entry 23
 15, 15, 47, 44, 44, 47, 44, 44, 47, 15, 15, // Character '8', entry 24
 15, 15, 47, 44, 44, 2, 61, 45, 5, 15, 15, // Character '9', entry 25
 15, 15, 15, 15, 7, 15, 15, 15, 7, 15, 15, // Character ':', entry 26
 15, 15, 15, 15, 7, 15, 15, 15, 7, 7, 1, // Character ';', entry 27
 15, 15, 15, 45, 7, 1, 7, 45, 15, 15, 15, // Character '<', entry 28
 15, 15, 15, 15, 3, 15, 3, 15, 15, 15, 15, // Character '=', entry 29
 15, 15, 15, 1, 7, 45, 7, 1, 15, 15, 15, // Character '>', entry 30
 15, 15, 27, 9, 61, 45, 7, 15, 7, 15, 15, // Character '?', entry 31
 15, 15, 63, 69, 75, 36, 36, 62, 1, 63, 15, // Character '@', entry 32
 15, 15, 45, 45, 79, 79, 55, 69, 69, 15, 15, // Character 'A', entry 33
 15, 15, 48, 44, 44, 48, 44, 44, 48, 15, 15, // Character 'B', entry 34
 15, 15, 47, 44, 40, 40, 40, 44, 47, 15, 15, // Character 'C', entry 35
 15, 15, 14, 64, 44, 44, 44, 64, 14, 15, 15, // Character 'D', entry 36
 15, 15, 48, 40, 40, 14, 40, 40, 48, 15, 15, // Character 'E', entry 37
 15, 15, 48, 40, 40, 14, 40, 40, 40, 15, 15, // Character 'F', entry 38
 15, 15, 47, 44, 40, 26, 44, 44, 47, 15, 15, // Character 'G', entry 39
 15, 15, 44, 44, 44, 3, 44, 44, 44, 15, 15, // Character 'H', entry 40
 15, 15, 1, 1, 1, 1, 1, 1, 1, 15, 15, // Character 'I', entry 41
 15, 15, 61, 61, 61, 61, 44, 44, 47, 15, 15, // Character 'J', entry 42
 15, 15, 44, 64, 32, 66, 32, 64, 44, 15, 15, // Character 'K', entry 43
 15, 15, 40, 40, 40, 40, 40, 40, 48, 15, 15, // Character 'L', entry 44
 15, 15, 24, 28, 36, 41, 24, 24, 24, 15, 15, // Character 'M', entry 45
 15, 15, 53, 53, 16, 16, 26, 26, 44, 15, 15, // Character 'N', entry 46
 15, 15, 47, 44, 44, 44, 44, 44, 47, 15, 15, // Character 'O', entry 47
 15, 15, 48, 44, 44, 48, 40, 40, 40, 15, 15, // Character 'P', entry 48
 15, 15, 47, 44, 44, 44, 44, 16, 47, 45, 15, // Character 'Q', entry 49
 15, 15, 48, 44, 44, 48, 32, 64, 44, 15, 15, // Character 'R', entry 50
 15, 15, 47, 44, 40, 47, 61, 44, 47, 15, 15, // Character 'S', entry 51
 15, 15, 3, 7, 7, 7, 7, 7, 7, 15, 15, // Character 'T', entry 52
 15, 15, 44, 44, 44, 44, 44, 44, 47, 15, 15, // Character 'U', entry 53
 15, 15, 44, 44, 44, 17, 17, 7, 7, 15, 15, // Character 'V', entry 54
 15, 15, 24, 24, 37, 37, 79, 79, 79, 15, 15, // Character 'W', entry 55
 15, 15, 44, 44, 17, 7, 17, 44, 44, 15, 15, // Character 'X', entry 56
 15, 15, 44, 44, 17, 7, 7, 7, 7, 15, 15, // Character 'Y', entry 57
 15, 15, 48, 45, 7, 1, 40, 40, 48, 15, 15, // Character 'Z', entry 58
 15, 5, 1, 1, 1, 1, 1, 1, 1, 5, 15, // Character '[', entry 59
 15, 1, 1, 7, 7, 45, 45, 61, 61, 15, 15, // Character '\', entry 60
 15, 5, 7, 7, 7, 7, 7, 7, 7, 5, 15, // Character ']', entry 61
 15, 15, 1, 32, 15, 15, 15, 15, 15, 15, 15, // Character '^', entry 62
 15, 15, 15, 15, 15, 15, 15, 15, 60, 15, 15, // Character '_', entry 63
 15, 15, 40, 1, 15, 15, 15, 15, 15, 15, 15, // Character '`', entry 64
 15, 15, 15, 15, 5, 45, 47, 64, 47, 15, 15, // Character 'a', entry 65
 15, 15, 40, 40, 14, 64, 64, 64, 14, 15, 15, // Character 'b', entry 66
 15, 15, 15, 15, 5, 64, 40, 64, 5, 15, 15, // Character 'c', entry 67
 15, 15, 45, 45, 47, 64, 64, 64, 47, 15, 15, // Character 'd', entry 68
 15, 15, 15, 15, 5, 64, 48, 40, 5, 15, 15, // Character 'e', entry 69
 15, 15, 27, 1, 14, 1, 1, 1, 1, 15, 15, // Character 'f', entry 70
 15, 15, 15, 15, 47, 64, 64, 64, 47, 45, 5, // Character 'g', entry 71
 15, 15, 40, 40, 14, 64, 64, 64, 64, 15, 15, // Character 'h', entry 72
 15, 15, 1, 15, 1, 1, 1, 1, 1, 15, 15, // Character 'i', entry 73
 15, 15, 7, 15, 7, 7, 7, 7, 7, 7, 66, // Character 'j', entry 74
 15, 15, 40, 40, 64, 32, 66, 32, 64, 15, 15, // Character 'k', entry 75
 15, 15, 1, 1, 1, 1, 1, 1, 1, 15, 15, // Character 'l', entry 76
 15, 15, 15, 15, 22, 41, 41, 41, 41, 15, 15, // Character 'm', entry 77
 15, 15, 15, 15, 14, 64, 64, 64, 64, 15, 15, // Character 'n', entry 78
 15, 15, 15, 15, 5, 64, 64, 64, 5, 15, 15, // Character 'o', entry 79
 15, 15, 15, 15, 14, 64, 64, 64, 14, 40, 40, // Character 'p', entry 80
 15, 15, 15, 15, 47, 64, 64, 64, 47, 45, 45, // Character 'q', entry 81
 15, 15, 15, 15, 51, 66, 40, 40, 40, 15, 15, // Character 'r', entry 82
 15, 15, 15, 15, 47, 40, 5, 45, 14, 15, 15, // Character 's', entry 83
 15, 15, 1, 1, 14, 1, 1, 1, 7, 15, 15, // Character 't', entry 84
 15, 15, 15, 15, 64, 64, 64, 64, 47, 15, 15, // Character 'u', entry 85
 15, 15, 15, 15, 44, 17, 17, 7, 7, 15, 15, // Character 'v', entry 86
 15, 15, 15, 15, 24, 37, 37, 79, 79, 15, 15, // Character 'w', entry 87
 15, 15, 15, 15, 44, 17, 7, 17, 44, 15, 15, // Character 'x', entry 88
 15, 15, 15, 15, 44, 44, 17, 17, 7, 7, 66, // Character 'y', entry 89
 15, 15, 15, 15, 48, 7, 1, 40, 48, 15, 15, // Character 'z', entry 90
 15, 7, 1, 1, 1, 40, 1, 1, 1, 7, 15, // Character '{', entry 91
 15, 40, 40, 40, 40, 40, 40, 40, 40, 40, 15, // Character '|', entry 92
 15, 40, 1, 1, 1, 7, 1, 1, 1, 40, 15, // Character '}', entry 93
 15, 15, 34, 51, 15, 15, 15, 15, 15, 15, 15, // Character '~', entry 94
 15, 15, 15, 15, 42, 42, 9, 9, 11, 40, 40, // Character 'µ', entry 95
 45, 15, 45, 45, 79, 79, 55, 69, 69, 15, 15, // Character 'À', entry 96
 45, 15, 45, 45, 79, 79, 55, 69, 69, 15, 15, // Character 'Á', entry 97
 15, 15, 21, 79, 79, 59, 9, 44, 67, 15, 15, // Character 'Æ', entry 98
 15, 15, 47, 44, 40, 40, 40, 44, 47, 7, 1, // Character 'Ç', entry 99
 7, 15, 48, 40, 40, 14, 40, 40, 48, 15, 15, // Character 'È', entry 100
 1, 15, 48, 40, 40, 14, 40, 40, 48, 15, 15, // Character 'É', entry 101
 32, 15, 48, 40, 40, 14, 40, 40, 48, 15, 15, // Character 'Ê', entry 102
 32, 15, 48, 40, 40, 14, 40, 40, 48, 15, 15, // Character 'Ë', entry 103
 15, 1, 7, 15, 5, 64, 47, 64, 47, 15, 15, // Character 'à', entry 104
 15, 7, 1, 15, 5, 64, 47, 64, 47, 15, 15, // Character 'á', entry 105
 15, 7, 17, 15, 5, 64, 47, 64, 47, 15, 15, // Character 'â', entry 106
 15, 17, 32, 15, 5, 64, 47, 64, 47, 15, 15, // Character 'ã', entry 107
 15, 15, 17, 15, 5, 64, 47, 64, 47, 15, 15, // Character 'ä', entry 108
 5, 64, 5, 15, 5, 64, 47, 64, 47, 15, 15, // Character 'å', entry 109
 15, 15, 15, 15, 56, 6, 58, 9, 56, 15, 15, // Character 'æ', entry 110
 15, 15, 15, 15, 5, 64, 40, 64, 5, 7, 1, // Character 'ç', entry 111
 15, 1, 7, 15, 5, 64, 48, 40, 5, 15, 15, // Character 'è', entry 112
 15, 7, 1, 15, 5, 64, 48, 40, 47, 15, 15, // Character 'é', entry 113
 15, 1, 32, 15, 5, 64, 48, 40, 5, 15, 15, // Character 'ê', entry 114
 15, 15, 64, 15, 5, 64, 48, 40, 47, 15, 15, // Character 'ë', entry 115
 15, 1, 7, 15, 64, 64, 64, 64, 47, 15, 15, // Character 'ù', entry 116
 15, 7, 1, 15, 64, 64, 64, 64, 47, 15, 15, // Character 'ú', entry 117
 15, 1, 32, 15, 64, 64, 64, 64, 47, 15, 15, // Character 'û', entry 118
 15, 15, 64, 15, 64, 64, 64, 64, 47, 15, 15, // Character 'ü', entry 119
 15, 15, 13, 44, 44, 30, 44, 44, 13, 15, 15, // Character 'Œ', entry 120
 15, 15, 15, 15, 4, 41, 71, 64, 55, 15, 15, // Character 'œ', entry 121
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const AWFontInternalDefinition Geneva9 = {
  9, // Font size
  9, // Ascender
  -1, // Descender
  7, // Range Count
  10, // Maximum Advancement
  0, // Empty Left Column Count
  8, // Column Count
  kRangeArray_Geneva9,
  kAdvancementArray_Geneva9,
  kHorizontalSegmentArray_Geneva9,
  kCharacterSegmentIndexArray8_Geneva9,
  NULL,
  "Geneva" // Font Name
} ; // 1601 bytes

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————


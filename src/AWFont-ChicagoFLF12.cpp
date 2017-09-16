#include "AWFont-ChicagoFLF12.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kRangeArray_ChicagoFLF12 [14] = {
 0x20,  0x7E,
 0xB5,  0xB5,
 0xC0,  0xC1,
 0xC6,  0xCB,
 0xE0,  0xEB,
 0xF9,  0xFC,
 0x152,  0x153
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint8_t kAdvancementArray_ChicagoFLF12 [122] = {
  4, // Character ' ', entry 0
  6, // Character '!', entry 1
  7, // Character '"', entry 2
  9, // Character '#', entry 3
  7, // Character '$', entry 4
  10, // Character '%', entry 5
  10, // Character '&', entry 6
  3, // Character ''', entry 7
  5, // Character '(', entry 8
  5, // Character ')', entry 9
  7, // Character '*', entry 10
  7, // Character '+', entry 11
  4, // Character ',', entry 12
  7, // Character '-', entry 13
  4, // Character '.', entry 14
  7, // Character '/', entry 15
  8, // Character '0', entry 16
  8, // Character '1', entry 17
  8, // Character '2', entry 18
  8, // Character '3', entry 19
  8, // Character '4', entry 20
  8, // Character '5', entry 21
  8, // Character '6', entry 22
  8, // Character '7', entry 23
  8, // Character '8', entry 24
  8, // Character '9', entry 25
  4, // Character ':', entry 26
  4, // Character ';', entry 27
  6, // Character '<', entry 28
  8, // Character '=', entry 29
  6, // Character '>', entry 30
  8, // Character '?', entry 31
  11, // Character '@', entry 32
  8, // Character 'A', entry 33
  8, // Character 'B', entry 34
  8, // Character 'C', entry 35
  8, // Character 'D', entry 36
  7, // Character 'E', entry 37
  7, // Character 'F', entry 38
  8, // Character 'G', entry 39
  8, // Character 'H', entry 40
  6, // Character 'I', entry 41
  7, // Character 'J', entry 42
  9, // Character 'K', entry 43
  7, // Character 'L', entry 44
  12, // Character 'M', entry 45
  9, // Character 'N', entry 46
  8, // Character 'O', entry 47
  8, // Character 'P', entry 48
  8, // Character 'Q', entry 49
  8, // Character 'R', entry 50
  7, // Character 'S', entry 51
  6, // Character 'T', entry 52
  8, // Character 'U', entry 53
  8, // Character 'V', entry 54
  12, // Character 'W', entry 55
  8, // Character 'X', entry 56
  8, // Character 'Y', entry 57
  8, // Character 'Z', entry 58
  5, // Character '[', entry 59
  8, // Character '\', entry 60
  5, // Character ']', entry 61
  8, // Character '^', entry 62
  8, // Character '_', entry 63
  6, // Character '`', entry 64
  8, // Character 'a', entry 65
  8, // Character 'b', entry 66
  7, // Character 'c', entry 67
  8, // Character 'd', entry 68
  8, // Character 'e', entry 69
  6, // Character 'f', entry 70
  8, // Character 'g', entry 71
  8, // Character 'h', entry 72
  4, // Character 'i', entry 73
  6, // Character 'j', entry 74
  8, // Character 'k', entry 75
  4, // Character 'l', entry 76
  12, // Character 'm', entry 77
  8, // Character 'n', entry 78
  8, // Character 'o', entry 79
  8, // Character 'p', entry 80
  8, // Character 'q', entry 81
  6, // Character 'r', entry 82
  7, // Character 's', entry 83
  6, // Character 't', entry 84
  8, // Character 'u', entry 85
  8, // Character 'v', entry 86
  12, // Character 'w', entry 87
  8, // Character 'x', entry 88
  8, // Character 'y', entry 89
  8, // Character 'z', entry 90
  5, // Character '{', entry 91
  5, // Character '|', entry 92
  5, // Character '}', entry 93
  8, // Character '~', entry 94
  10, // Character 'µ', entry 95
  8, // Character 'À', entry 96
  8, // Character 'Á', entry 97
  11, // Character 'Æ', entry 98
  8, // Character 'Ç', entry 99
  7, // Character 'È', entry 100
  7, // Character 'É', entry 101
  7, // Character 'Ê', entry 102
  7, // Character 'Ë', entry 103
  8, // Character 'à', entry 104
  8, // Character 'á', entry 105
  8, // Character 'â', entry 106
  8, // Character 'ã', entry 107
  8, // Character 'ä', entry 108
  8, // Character 'å', entry 109
  12, // Character 'æ', entry 110
  7, // Character 'ç', entry 111
  8, // Character 'è', entry 112
  8, // Character 'é', entry 113
  8, // Character 'ê', entry 114
  8, // Character 'ë', entry 115
  8, // Character 'ù', entry 116
  8, // Character 'ú', entry 117
  8, // Character 'û', entry 118
  8, // Character 'ü', entry 119
  11, // Character 'Œ', entry 120
  12, // Character 'œ', entry 121
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint8_t kHorizontalSegmentArray_ChicagoFLF12 [143] = {
 0x15, 0x34, // Index 0
 0x13, 0x36, // Index 2
 0x13, 0x1B, 0x14, // Index 4
 0x25, 0x22, // Index 7
 0x13, 0x2C, // Index 9
 0x1C, // Index 11
 0x13, 0x23, 0x12, // Index 12
 0x43, 0x22, // Index 15
 0x17, 0x46, // Index 17
 0x15, 0x28, // Index 19
 0x0, // Index 21
 0x13, 0x72, // Index 22
 0x13, 0x24, // Index 24
 0x15, 0x25, 0x14, // Index 26
 0x13, 0x13, 0x12, // Index 29
 0x15, 0x25, 0x12, // Index 32
 0x38, // Index 35
 0x15, 0x64, // Index 36
 0x15, 0x25, 0x24, // Index 38
 0x15, 0x24, // Index 41
 0x13, 0x33, 0x34, // Index 43
 0x13, 0x52, // Index 46
 0x54, // Index 48
 0x1F, 0x4, // Index 49
 0x15, 0x25, 0x32, // Index 51
 0x25, 0x42, // Index 54
 0x1F, 0x2, // Index 56
 0x2F, 0x2, // Index 58
 0x3, 0x24, // Index 60
 0x15, 0x32, // Index 62
 0x35, 0x12, // Index 64
 0x13, 0x74, // Index 66
 0x19, 0x22, // Index 68
 0x15, 0x22, // Index 70
 0x13, 0x28, // Index 72
 0x1E, // Index 74
 0x15, 0x26, // Index 75
 0x15, 0x2C, // Index 77
 0x17, 0x32, // Index 79
 0x13, 0x82, // Index 81
 0x18, // Index 83
 0x13, 0x34, // Index 84
 0x35, 0x13, 0x12, // Index 86
 0x13, 0x35, 0x24, // Index 89
 0x33, 0x12, // Index 92
 0x19, 0x28, // Index 94
 0x15, 0x14, // Index 96
 0x13, 0x13, 0x23, 0x22, // Index 98
 0x2B, 0x24, // Index 102
 0x15, 0x2A, // Index 104
 0x2E, // Index 106
 0x5, 0x24, // Index 107
 0x23, 0x24, // Index 109
 0x15, 0x16, // Index 111
 0x15, 0x42, // Index 113
 0x23, 0x14, // Index 115
 0x1A, // Index 117
 0x13, 0x44, // Index 118
 0xF, 0x2, // Index 120
 0x13, 0x17, 0x12, // Index 122
 0x33, 0x13, 0x22, // Index 125
 0x33, 0x22, // Index 128
 0x13, 0x27, 0x22, // Index 130
 0x13, 0x27, 0x24, // Index 133
 0xC, // Index 136
 0x25, 0x26, // Index 137
 0x15, 0x12, // Index 139
 0x2B, 0x12, // Index 141
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint8_t kCharacterSegmentIndexArray8_ChicagoFLF12 [1586] = {
 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, // Character ' ', entry 0
 21, 21, 25, 25, 25, 25, 25, 25, 21, 25, 25, 21, 21, // Character '!', entry 1
 21, 21, 13, 13, 13, 21, 21, 21, 21, 21, 21, 21, 21, // Character '"', entry 2
 21, 21, 64, 128, 10, 92, 11, 100, 115, 21, 21, 21, 21, // Character '#', entry 3
 21, 53, 76, 29, 112, 112, 76, 3, 3, 29, 76, 53, 21, // Character '$', entry 4
 21, 21, 10, 12, 29, 100, 119, 15, 86, 125, 137, 21, 21, // Character '%', entry 5
 21, 21, 20, 41, 32, 54, 75, 41, 41, 41, 20, 21, 21, // Character '&', entry 6
 21, 21, 142, 142, 21, 21, 21, 21, 21, 21, 21, 21, 21, // Character ''', entry 7
 21, 53, 8, 6, 6, 6, 6, 6, 6, 6, 6, 25, 21, // Character '(', entry 8
 21, 142, 8, 25, 25, 25, 25, 25, 25, 25, 25, 6, 21, // Character ')', entry 9
 21, 53, 53, 117, 1, 117, 53, 21, 21, 21, 21, 21, 21, // Character '*', entry 10
 21, 21, 21, 21, 53, 53, 117, 53, 53, 21, 21, 21, 21, // Character '+', entry 11
 21, 21, 21, 21, 21, 21, 21, 21, 21, 6, 6, 8, 6, // Character ',', entry 12
 21, 21, 21, 21, 21, 21, 117, 21, 21, 21, 21, 21, 21, // Character '-', entry 13
 21, 21, 21, 21, 21, 21, 21, 21, 21, 6, 6, 21, 21, // Character '.', entry 14
 21, 47, 47, 55, 55, 53, 53, 8, 8, 8, 142, 21, 21, // Character '/', entry 15
 21, 21, 20, 41, 41, 41, 41, 41, 41, 41, 20, 21, 21, // Character '0', entry 16
 21, 21, 76, 76, 1, 1, 1, 1, 1, 1, 1, 21, 21, // Character '1', entry 17
 21, 21, 20, 84, 48, 48, 119, 1, 25, 6, 11, 21, 21, // Character '2', entry 18
 21, 21, 11, 119, 1, 20, 48, 48, 48, 84, 20, 21, 21, // Character '3', entry 19
 21, 21, 18, 35, 27, 41, 84, 74, 48, 48, 48, 21, 21, // Character '4', entry 20
 21, 21, 11, 6, 6, 117, 48, 48, 48, 84, 20, 21, 21, // Character '5', entry 21
 21, 21, 3, 25, 6, 117, 41, 41, 41, 41, 20, 21, 21, // Character '6', entry 22
 21, 21, 11, 48, 48, 48, 119, 1, 1, 1, 1, 21, 21, // Character '7', entry 23
 21, 21, 20, 41, 41, 41, 20, 41, 41, 41, 20, 21, 21, // Character '8', entry 24
 21, 21, 20, 41, 41, 41, 41, 105, 48, 119, 76, 21, 21, // Character '9', entry 25
 21, 21, 21, 21, 6, 6, 21, 21, 21, 6, 6, 21, 21, // Character ':', entry 26
 21, 21, 21, 21, 6, 6, 21, 21, 21, 6, 6, 8, 6, // Character ';', entry 27
 21, 21, 21, 3, 25, 6, 6, 25, 3, 21, 21, 21, 21, // Character '<', entry 28
 21, 21, 21, 21, 21, 11, 21, 11, 21, 21, 21, 21, 21, // Character '=', entry 29
 21, 21, 21, 6, 25, 1, 3, 25, 6, 21, 21, 21, 21, // Character '>', entry 30
 21, 21, 20, 84, 48, 119, 1, 1, 21, 1, 1, 21, 21, // Character '?', entry 31
 21, 21, 21, 106, 22, 130, 98, 98, 9, 142, 10, 21, 21, // Character '@', entry 32
 21, 21, 20, 41, 41, 41, 11, 41, 41, 41, 41, 21, 21, // Character 'A', entry 33
 21, 21, 117, 41, 41, 41, 117, 41, 41, 41, 117, 21, 21, // Character 'B', entry 34
 21, 21, 20, 62, 6, 6, 6, 6, 6, 62, 20, 21, 21, // Character 'C', entry 35
 21, 21, 117, 41, 41, 41, 41, 41, 41, 41, 117, 21, 21, // Character 'D', entry 36
 21, 21, 117, 6, 6, 6, 83, 6, 6, 6, 117, 21, 21, // Character 'E', entry 37
 21, 21, 117, 6, 6, 6, 83, 6, 6, 6, 6, 21, 21, // Character 'F', entry 38
 21, 21, 20, 62, 6, 6, 111, 41, 41, 41, 20, 21, 21, // Character 'G', entry 39
 21, 21, 41, 41, 41, 41, 11, 41, 41, 41, 41, 21, 21, // Character 'H', entry 40
 21, 21, 25, 25, 25, 25, 25, 25, 25, 25, 25, 21, 21, // Character 'I', entry 41
 21, 21, 119, 119, 119, 119, 119, 107, 107, 107, 83, 21, 21, // Character 'J', entry 42
 21, 21, 0, 70, 139, 112, 112, 83, 96, 41, 0, 21, 21, // Character 'K', entry 43
 21, 21, 6, 6, 6, 6, 6, 6, 6, 6, 117, 21, 21, // Character 'L', entry 44
 21, 21, 81, 36, 17, 94, 4, 133, 43, 66, 66, 21, 21, // Character 'M', entry 45
 21, 21, 46, 113, 79, 68, 122, 72, 2, 118, 46, 21, 21, // Character 'N', entry 46
 21, 21, 20, 41, 41, 41, 41, 41, 41, 41, 20, 21, 21, // Character 'O', entry 47
 21, 21, 117, 41, 41, 41, 117, 6, 6, 6, 6, 21, 21, // Character 'P', entry 48
 21, 21, 20, 41, 41, 41, 41, 41, 41, 41, 20, 48, 21, // Character 'Q', entry 49
 21, 21, 117, 41, 41, 41, 117, 41, 41, 41, 41, 21, 21, // Character 'R', entry 50
 21, 21, 76, 70, 6, 112, 76, 3, 119, 24, 76, 21, 21, // Character 'S', entry 51
 21, 21, 136, 25, 25, 25, 25, 25, 25, 25, 25, 21, 21, // Character 'T', entry 52
 21, 21, 41, 41, 41, 41, 41, 41, 41, 41, 20, 21, 21, // Character 'U', entry 53
 21, 21, 41, 41, 41, 41, 41, 41, 41, 70, 83, 21, 21, // Character 'V', entry 54
 21, 21, 38, 38, 38, 38, 38, 38, 38, 26, 56, 21, 21, // Character 'W', entry 55
 21, 21, 41, 41, 41, 41, 20, 41, 41, 41, 41, 21, 21, // Character 'X', entry 56
 21, 21, 41, 41, 41, 100, 1, 1, 1, 1, 1, 21, 21, // Character 'Y', entry 57
 21, 21, 11, 48, 48, 119, 1, 25, 6, 6, 11, 21, 21, // Character 'Z', entry 58
 21, 112, 6, 6, 6, 6, 6, 6, 6, 6, 6, 112, 21, // Character '[', entry 59
 21, 142, 8, 8, 53, 53, 53, 55, 55, 47, 47, 48, 21, // Character '\', entry 60
 21, 112, 25, 25, 25, 25, 25, 25, 25, 25, 25, 112, 21, // Character ']', entry 61
 21, 21, 55, 1, 109, 21, 21, 21, 21, 21, 21, 21, 21, // Character '^', entry 62
 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 120, 21, 21, // Character '_', entry 63
 21, 6, 53, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, // Character '`', entry 64
 21, 21, 21, 21, 20, 84, 105, 41, 41, 41, 105, 21, 21, // Character 'a', entry 65
 21, 21, 6, 6, 117, 41, 41, 41, 41, 41, 117, 21, 21, // Character 'b', entry 66
 21, 21, 21, 21, 76, 70, 6, 6, 6, 70, 76, 21, 21, // Character 'c', entry 67
 21, 21, 48, 48, 105, 41, 41, 41, 41, 41, 105, 21, 21, // Character 'd', entry 68
 21, 21, 21, 21, 20, 41, 41, 11, 6, 62, 20, 21, 21, // Character 'e', entry 69
 21, 21, 20, 25, 83, 25, 25, 25, 25, 25, 25, 21, 21, // Character 'f', entry 70
 21, 21, 21, 21, 105, 41, 41, 41, 41, 41, 105, 84, 11, // Character 'g', entry 71
 21, 21, 6, 6, 117, 41, 41, 41, 41, 41, 41, 21, 21, // Character 'h', entry 72
 21, 21, 6, 21, 6, 6, 6, 6, 6, 6, 6, 21, 21, // Character 'i', entry 73
 21, 21, 1, 21, 1, 1, 1, 1, 1, 1, 1, 60, 112, // Character 'j', entry 74
 21, 21, 6, 6, 41, 139, 112, 112, 83, 96, 41, 21, 21, // Character 'k', entry 75
 21, 21, 6, 6, 6, 6, 6, 6, 6, 6, 6, 21, 21, // Character 'l', entry 76
 21, 21, 21, 21, 49, 38, 38, 38, 38, 38, 38, 21, 21, // Character 'm', entry 77
 21, 21, 21, 21, 117, 41, 41, 41, 41, 41, 41, 21, 21, // Character 'n', entry 78
 21, 21, 21, 21, 20, 41, 41, 41, 41, 41, 20, 21, 21, // Character 'o', entry 79
 21, 21, 21, 21, 117, 41, 41, 41, 41, 41, 117, 6, 6, // Character 'p', entry 80
 21, 21, 21, 21, 105, 41, 41, 41, 41, 41, 105, 48, 48, // Character 'q', entry 81
 21, 21, 21, 21, 96, 112, 6, 6, 6, 6, 6, 21, 21, // Character 'r', entry 82
 21, 21, 21, 21, 76, 70, 112, 76, 3, 24, 76, 21, 21, // Character 's', entry 83
 21, 21, 25, 25, 83, 25, 25, 25, 25, 25, 76, 21, 21, // Character 't', entry 84
 21, 21, 21, 21, 41, 41, 41, 41, 41, 41, 105, 21, 21, // Character 'u', entry 85
 21, 21, 21, 21, 41, 41, 41, 41, 41, 96, 83, 21, 21, // Character 'v', entry 86
 21, 21, 21, 21, 38, 38, 38, 38, 38, 26, 56, 21, 21, // Character 'w', entry 87
 21, 21, 21, 21, 41, 41, 41, 20, 41, 41, 41, 21, 21, // Character 'x', entry 88
 21, 21, 21, 21, 41, 41, 41, 41, 41, 41, 35, 84, 11, // Character 'y', entry 89
 21, 21, 21, 21, 11, 48, 119, 1, 25, 6, 11, 21, 21, // Character 'z', entry 90
 21, 21, 25, 8, 8, 8, 8, 142, 8, 8, 8, 8, 53, // Character '{', entry 91
 21, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 21, // Character '|', entry 92
 21, 142, 8, 8, 8, 8, 8, 25, 8, 8, 8, 8, 142, // Character '}', entry 93
 21, 21, 21, 21, 7, 24, 21, 21, 21, 21, 21, 21, 21, // Character '~', entry 94
 21, 21, 21, 21, 39, 39, 39, 39, 39, 39, 141, 8, 142, // Character 'µ', entry 95
 53, 55, 20, 41, 41, 41, 11, 41, 41, 41, 41, 21, 21, // Character 'À', entry 96
 55, 53, 20, 41, 41, 41, 11, 41, 41, 41, 41, 21, 21, // Character 'Á', entry 97
 21, 21, 58, 41, 41, 41, 56, 41, 41, 41, 104, 21, 21, // Character 'Æ', entry 98
 21, 21, 20, 62, 6, 6, 6, 6, 6, 62, 20, 1, 1, // Character 'Ç', entry 99
 53, 55, 117, 6, 6, 6, 83, 6, 6, 6, 117, 21, 21, // Character 'È', entry 100
 55, 53, 117, 6, 6, 6, 83, 6, 6, 6, 117, 21, 21, // Character 'É', entry 101
 53, 13, 117, 6, 6, 6, 83, 6, 6, 6, 117, 21, 21, // Character 'Ê', entry 102
 21, 13, 117, 6, 6, 6, 83, 6, 6, 6, 117, 21, 21, // Character 'Ë', entry 103
 21, 8, 53, 55, 20, 84, 105, 41, 41, 41, 105, 21, 21, // Character 'à', entry 104
 21, 47, 55, 53, 20, 84, 105, 41, 41, 41, 105, 21, 21, // Character 'á', entry 105
 21, 53, 1, 100, 20, 84, 105, 41, 41, 41, 105, 21, 21, // Character 'â', entry 106
 21, 21, 105, 142, 20, 84, 105, 41, 41, 41, 105, 21, 21, // Character 'ã', entry 107
 21, 21, 100, 21, 20, 84, 105, 41, 41, 41, 105, 21, 21, // Character 'ä', entry 108
 76, 13, 76, 21, 117, 84, 105, 41, 41, 41, 105, 21, 21, // Character 'å', entry 109
 21, 21, 21, 21, 58, 89, 102, 77, 41, 51, 58, 21, 21, // Character 'æ', entry 110
 21, 21, 21, 21, 76, 70, 6, 6, 6, 70, 76, 53, 25, // Character 'ç', entry 111
 21, 8, 53, 55, 20, 41, 41, 11, 6, 62, 20, 21, 21, // Character 'è', entry 112
 21, 47, 55, 53, 20, 41, 41, 11, 6, 62, 20, 21, 21, // Character 'é', entry 113
 21, 53, 1, 100, 20, 41, 41, 11, 6, 62, 20, 21, 21, // Character 'ê', entry 114
 21, 21, 100, 21, 20, 41, 41, 11, 6, 62, 20, 21, 21, // Character 'ë', entry 115
 21, 8, 53, 55, 41, 41, 41, 41, 41, 41, 105, 21, 21, // Character 'ù', entry 116
 21, 47, 55, 53, 41, 41, 41, 41, 41, 41, 105, 21, 21, // Character 'ú', entry 117
 21, 53, 1, 100, 41, 41, 41, 41, 41, 41, 105, 21, 21, // Character 'û', entry 118
 21, 21, 100, 21, 41, 41, 41, 41, 41, 41, 105, 21, 21, // Character 'ü', entry 119
 21, 21, 58, 41, 41, 41, 19, 41, 41, 41, 58, 21, 21, // Character 'Œ', entry 120
 21, 21, 21, 21, 58, 38, 38, 77, 41, 51, 58, 21, 21, // Character 'œ', entry 121
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const AWFontInternalDefinition ChicagoFLF12 = {
  12, // Font size
  11, // Ascender
  -1, // Descender
  7, // Range Count
  12, // Maximum Advancement
  0, // Empty Left Column Count
  11, // Column Count
  kRangeArray_ChicagoFLF12,
  kAdvancementArray_ChicagoFLF12,
  kHorizontalSegmentArray_ChicagoFLF12,
  kCharacterSegmentIndexArray8_ChicagoFLF12,
  NULL,
  "ChicagoFLF" // Font Name
} ; // 1907 bytes

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————


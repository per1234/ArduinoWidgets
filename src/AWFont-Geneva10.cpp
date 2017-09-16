#include "AWFont-Geneva10.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kRangeArray_Geneva10 [14] = {
 0x20,  0x7E,
 0xB5,  0xB5,
 0xC0,  0xC1,
 0xC6,  0xCB,
 0xE0,  0xEB,
 0xF9,  0xFC,
 0x152,  0x153
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint8_t kAdvancementArray_Geneva10 [122] = {
  3, // Character ' ', entry 0
  3, // Character '!', entry 1
  5, // Character '"', entry 2
  7, // Character '#', entry 3
  7, // Character '$', entry 4
  9, // Character '%', entry 5
  7, // Character '&', entry 6
  3, // Character ''', entry 7
  4, // Character '(', entry 8
  4, // Character ')', entry 9
  5, // Character '*', entry 10
  7, // Character '+', entry 11
  3, // Character ',', entry 12
  4, // Character '-', entry 13
  3, // Character '.', entry 14
  5, // Character '/', entry 15
  7, // Character '0', entry 16
  7, // Character '1', entry 17
  7, // Character '2', entry 18
  7, // Character '3', entry 19
  7, // Character '4', entry 20
  7, // Character '5', entry 21
  7, // Character '6', entry 22
  7, // Character '7', entry 23
  7, // Character '8', entry 24
  7, // Character '9', entry 25
  3, // Character ':', entry 26
  3, // Character ';', entry 27
  7, // Character '<', entry 28
  7, // Character '=', entry 29
  7, // Character '>', entry 30
  6, // Character '?', entry 31
  9, // Character '@', entry 32
  7, // Character 'A', entry 33
  6, // Character 'B', entry 34
  7, // Character 'C', entry 35
  7, // Character 'D', entry 36
  6, // Character 'E', entry 37
  6, // Character 'F', entry 38
  7, // Character 'G', entry 39
  7, // Character 'H', entry 40
  2, // Character 'I', entry 41
  5, // Character 'J', entry 42
  7, // Character 'K', entry 43
  6, // Character 'L', entry 44
  8, // Character 'M', entry 45
  7, // Character 'N', entry 46
  7, // Character 'O', entry 47
  6, // Character 'P', entry 48
  7, // Character 'Q', entry 49
  6, // Character 'R', entry 50
  6, // Character 'S', entry 51
  6, // Character 'T', entry 52
  7, // Character 'U', entry 53
  7, // Character 'V', entry 54
  9, // Character 'W', entry 55
  6, // Character 'X', entry 56
  6, // Character 'Y', entry 57
  6, // Character 'Z', entry 58
  4, // Character '[', entry 59
  5, // Character '\', entry 60
  4, // Character ']', entry 61
  7, // Character '^', entry 62
  7, // Character '_', entry 63
  6, // Character '`', entry 64
  6, // Character 'a', entry 65
  6, // Character 'b', entry 66
  5, // Character 'c', entry 67
  6, // Character 'd', entry 68
  6, // Character 'e', entry 69
  4, // Character 'f', entry 70
  6, // Character 'g', entry 71
  6, // Character 'h', entry 72
  2, // Character 'i', entry 73
  3, // Character 'j', entry 74
  5, // Character 'k', entry 75
  2, // Character 'l', entry 76
  9, // Character 'm', entry 77
  6, // Character 'n', entry 78
  6, // Character 'o', entry 79
  6, // Character 'p', entry 80
  6, // Character 'q', entry 81
  4, // Character 'r', entry 82
  5, // Character 's', entry 83
  4, // Character 't', entry 84
  6, // Character 'u', entry 85
  6, // Character 'v', entry 86
  8, // Character 'w', entry 87
  5, // Character 'x', entry 88
  6, // Character 'y', entry 89
  6, // Character 'z', entry 90
  5, // Character '{', entry 91
  2, // Character '|', entry 92
  5, // Character '}', entry 93
  7, // Character '~', entry 94
  6, // Character 'µ', entry 95
  7, // Character 'À', entry 96
  7, // Character 'Á', entry 97
  10, // Character 'Æ', entry 98
  7, // Character 'Ç', entry 99
  6, // Character 'È', entry 100
  6, // Character 'É', entry 101
  6, // Character 'Ê', entry 102
  6, // Character 'Ë', entry 103
  6, // Character 'à', entry 104
  6, // Character 'á', entry 105
  6, // Character 'â', entry 106
  6, // Character 'ã', entry 107
  6, // Character 'ä', entry 108
  6, // Character 'å', entry 109
  9, // Character 'æ', entry 110
  5, // Character 'ç', entry 111
  6, // Character 'è', entry 112
  6, // Character 'é', entry 113
  6, // Character 'ê', entry 114
  6, // Character 'ë', entry 115
  6, // Character 'ù', entry 116
  6, // Character 'ú', entry 117
  6, // Character 'û', entry 118
  6, // Character 'ü', entry 119
  11, // Character 'Œ', entry 120
  10, // Character 'œ', entry 121
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint8_t kHorizontalSegmentArray_Geneva10 [99] = {
 0x2C, // Index 0
 0x23, 0x34, // Index 1
 0x43, 0x14, // Index 3
 0x13, 0x52, // Index 5
 0x1A, // Index 7
 0x2E, // Index 8
 0x15, 0x34, // Index 9
 0x23, 0x32, // Index 11
 0xE, // Index 13
 0x23, 0x23, 0x22, // Index 14
 0x13, 0x13, 0x13, 0x12, // Index 17
 0x3, 0x36, // Index 21
 0x25, 0x12, // Index 23
 0x23, 0x16, // Index 25
 0x13, 0x18, // Index 27
 0x3, 0x24, // Index 29
 0x3, 0x23, 0x22, // Index 31
 0x15, 0x22, // Index 34
 0x17, 0x16, // Index 36
 0x13, 0x14, // Index 38
 0x15, 0x32, // Index 40
 0x3A, // Index 42
 0x4, // Index 43
 0xA, // Index 44
 0x44, // Index 45
 0x3, 0x33, 0x32, // Index 46
 0x3, 0x38, // Index 49
 0x13, 0x17, 0x12, // Index 51
 0x3, 0x32, // Index 54
 0x15, 0x14, // Index 56
 0x1C, // Index 58
 0x6, // Index 59
 0x3, 0x72, // Index 60
 0x13, 0x32, // Index 62
 0x2, // Index 64
 0x33, 0x13, 0x22, // Index 65
 0x3, 0x22, // Index 68
 0x42, // Index 70
 0x43, 0x12, // Index 71
 0x26, // Index 73
 0x3, 0x28, // Index 74
 0x3, 0x14, // Index 76
 0x13, 0x23, 0x12, // Index 78
 0x0, // Index 81
 0x33, 0x12, // Index 82
 0x3, 0x52, // Index 84
 0x13, 0x23, 0x22, // Index 86
 0x3, 0x23, 0x12, // Index 89
 0x13, 0x24, // Index 92
 0x17, 0x14, // Index 94
 0x8, // Index 96
 0x15, 0x12, // Index 97
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint8_t kCharacterSegmentIndexArray8_Geneva10 [1464] = {
 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, // Character ' ', entry 0
 81, 81, 16, 16, 16, 16, 16, 16, 81, 16, 81, 81, // Character '!', entry 1
 81, 81, 19, 19, 81, 81, 81, 81, 81, 81, 81, 81, // Character '"', entry 2
 81, 81, 71, 0, 82, 58, 79, 81, 81, 81, 81, 81, // Character '#', entry 3
 81, 12, 73, 18, 19, 30, 2, 82, 18, 73, 12, 81, // Character '$', entry 4
 81, 81, 8, 86, 78, 23, 3, 65, 14, 1, 81, 81, // Character '%', entry 5
 81, 81, 30, 66, 19, 16, 18, 54, 89, 40, 81, 81, // Character '&', entry 6
 81, 81, 98, 98, 81, 81, 81, 81, 81, 81, 81, 81, // Character ''', entry 7
 81, 12, 16, 16, 98, 98, 98, 98, 16, 16, 12, 81, // Character '(', entry 8
 81, 98, 16, 16, 12, 12, 12, 12, 16, 16, 98, 81, // Character ')', entry 9
 81, 81, 12, 18, 73, 79, 62, 81, 81, 81, 81, 81, // Character '*', entry 10
 81, 81, 81, 81, 12, 12, 7, 12, 12, 81, 81, 81, // Character '+', entry 11
 81, 81, 81, 81, 81, 81, 81, 81, 81, 16, 16, 98, // Character ',', entry 12
 81, 81, 81, 81, 81, 81, 28, 81, 81, 81, 81, 81, // Character '-', entry 13
 81, 81, 81, 81, 81, 81, 81, 81, 81, 98, 81, 81, // Character '.', entry 14
 81, 81, 70, 70, 12, 12, 16, 16, 98, 98, 81, 81, // Character '/', entry 15
 81, 81, 73, 62, 62, 62, 62, 62, 62, 73, 81, 81, // Character '0', entry 16
 81, 81, 12, 30, 12, 12, 12, 12, 12, 12, 81, 81, // Character '1', entry 17
 81, 81, 73, 62, 85, 70, 12, 16, 98, 7, 81, 81, // Character '2', entry 18
 81, 81, 7, 70, 12, 73, 85, 85, 62, 73, 81, 81, // Character '3', entry 19
 81, 81, 85, 45, 82, 15, 62, 58, 85, 85, 81, 81, // Character '4', entry 20
 81, 81, 7, 98, 98, 28, 85, 85, 62, 73, 81, 81, // Character '5', entry 21
 81, 81, 2, 16, 98, 28, 62, 62, 62, 73, 81, 81, // Character '6', entry 22
 81, 81, 7, 85, 85, 70, 70, 12, 12, 12, 81, 81, // Character '7', entry 23
 81, 81, 73, 62, 62, 73, 62, 62, 62, 73, 81, 81, // Character '8', entry 24
 81, 81, 73, 62, 62, 62, 75, 85, 70, 30, 81, 81, // Character '9', entry 25
 81, 81, 81, 81, 81, 98, 81, 81, 81, 98, 81, 81, // Character ':', entry 26
 81, 81, 81, 81, 81, 16, 81, 81, 81, 16, 16, 98, // Character ';', entry 27
 81, 81, 81, 81, 12, 16, 98, 16, 12, 81, 81, 81, // Character '<', entry 28
 81, 81, 81, 81, 81, 7, 81, 7, 81, 81, 81, 81, // Character '=', entry 29
 81, 81, 81, 81, 98, 16, 12, 16, 98, 81, 81, 81, // Character '>', entry 30
 81, 81, 73, 62, 85, 70, 12, 12, 81, 12, 81, 81, // Character '?', entry 31
 81, 81, 81, 22, 11, 51, 17, 27, 16, 2, 81, 81, // Character '@', entry 32
 81, 81, 16, 16, 19, 19, 54, 44, 54, 54, 81, 81, // Character 'A', entry 33
 81, 81, 28, 62, 62, 28, 62, 62, 62, 28, 81, 81, // Character 'B', entry 34
 81, 81, 26, 54, 64, 64, 64, 64, 54, 26, 81, 81, // Character 'C', entry 35
 81, 81, 26, 66, 62, 62, 62, 62, 66, 26, 81, 81, // Character 'D', entry 36
 81, 81, 28, 98, 98, 26, 98, 98, 98, 28, 81, 81, // Character 'E', entry 37
 81, 81, 28, 98, 98, 26, 98, 98, 98, 98, 81, 81, // Character 'F', entry 38
 81, 81, 26, 54, 64, 64, 29, 54, 54, 26, 81, 81, // Character 'G', entry 39
 81, 81, 62, 62, 62, 7, 62, 62, 62, 62, 81, 81, // Character 'H', entry 40
 81, 81, 98, 98, 98, 98, 98, 98, 98, 98, 81, 81, // Character 'I', entry 41
 81, 81, 70, 70, 70, 70, 70, 54, 54, 26, 81, 81, // Character 'J', entry 42
 81, 81, 62, 66, 19, 4, 4, 19, 66, 62, 81, 81, // Character 'K', entry 43
 81, 81, 98, 98, 98, 98, 98, 98, 98, 28, 81, 81, // Character 'L', entry 44
 81, 81, 5, 9, 17, 86, 5, 5, 5, 5, 81, 81, // Character 'M', entry 45
 81, 81, 62, 34, 34, 18, 18, 92, 92, 62, 81, 81, // Character 'N', entry 46
 81, 81, 26, 54, 54, 54, 54, 54, 54, 26, 81, 81, // Character 'O', entry 47
 81, 81, 28, 62, 62, 62, 28, 98, 98, 98, 81, 81, // Character 'P', entry 48
 81, 81, 26, 54, 54, 54, 54, 54, 54, 26, 16, 2, // Character 'Q', entry 49
 81, 81, 28, 62, 62, 62, 28, 66, 62, 62, 81, 81, // Character 'R', entry 50
 81, 81, 26, 54, 64, 26, 70, 70, 54, 26, 81, 81, // Character 'S', entry 51
 81, 81, 44, 16, 16, 16, 16, 16, 16, 16, 81, 81, // Character 'T', entry 52
 81, 81, 62, 62, 62, 62, 62, 62, 62, 73, 81, 81, // Character 'U', entry 53
 81, 81, 54, 54, 19, 19, 19, 16, 16, 16, 81, 81, // Character 'V', entry 54
 81, 81, 60, 46, 86, 17, 17, 11, 11, 11, 81, 81, // Character 'W', entry 55
 81, 81, 54, 54, 19, 16, 16, 19, 54, 54, 81, 81, // Character 'X', entry 56
 81, 81, 54, 54, 19, 19, 16, 16, 16, 16, 81, 81, // Character 'Y', entry 57
 81, 81, 44, 70, 12, 16, 16, 98, 64, 44, 81, 81, // Character 'Z', entry 58
 81, 4, 98, 98, 98, 98, 98, 98, 98, 98, 4, 81, // Character '[', entry 59
 81, 81, 64, 64, 98, 98, 16, 16, 12, 12, 81, 81, // Character '\', entry 60
 81, 4, 16, 16, 16, 16, 16, 16, 16, 16, 4, 81, // Character ']', entry 61
 81, 81, 16, 19, 54, 81, 81, 81, 81, 81, 81, 81, // Character '^', entry 62
 81, 81, 81, 81, 81, 81, 81, 81, 81, 13, 81, 81, // Character '_', entry 63
 81, 81, 98, 16, 81, 81, 81, 81, 81, 81, 81, 81, // Character '`', entry 64
 81, 81, 81, 81, 4, 68, 26, 68, 68, 26, 81, 81, // Character 'a', entry 65
 81, 81, 98, 98, 26, 66, 66, 66, 66, 26, 81, 81, // Character 'b', entry 66
 81, 81, 81, 81, 4, 68, 64, 64, 68, 4, 81, 81, // Character 'c', entry 67
 81, 81, 12, 12, 26, 68, 68, 68, 68, 26, 81, 81, // Character 'd', entry 68
 81, 81, 81, 81, 4, 68, 96, 64, 68, 4, 81, 81, // Character 'e', entry 69
 81, 81, 30, 98, 59, 98, 98, 98, 98, 98, 81, 81, // Character 'f', entry 70
 81, 81, 81, 81, 26, 68, 68, 68, 68, 26, 12, 4, // Character 'g', entry 71
 81, 81, 98, 98, 26, 66, 66, 66, 66, 66, 81, 81, // Character 'h', entry 72
 81, 81, 98, 81, 98, 98, 98, 98, 98, 98, 81, 81, // Character 'i', entry 73
 81, 81, 16, 81, 16, 16, 16, 16, 16, 16, 16, 43, // Character 'j', entry 74
 81, 81, 98, 98, 66, 19, 4, 4, 19, 66, 81, 81, // Character 'k', entry 75
 81, 81, 98, 98, 98, 98, 98, 98, 98, 98, 81, 81, // Character 'l', entry 76
 81, 81, 81, 81, 94, 86, 86, 86, 86, 86, 81, 81, // Character 'm', entry 77
 81, 81, 81, 81, 26, 66, 66, 66, 66, 66, 81, 81, // Character 'n', entry 78
 81, 81, 81, 81, 4, 68, 68, 68, 68, 4, 81, 81, // Character 'o', entry 79
 81, 81, 81, 81, 26, 66, 66, 66, 66, 26, 98, 98, // Character 'p', entry 80
 81, 81, 81, 81, 26, 68, 68, 68, 68, 26, 12, 12, // Character 'q', entry 81
 81, 81, 81, 81, 38, 4, 98, 98, 98, 98, 81, 81, // Character 'r', entry 82
 81, 81, 81, 81, 4, 68, 4, 12, 68, 4, 81, 81, // Character 's', entry 83
 81, 81, 98, 98, 59, 98, 98, 98, 98, 16, 81, 81, // Character 't', entry 84
 81, 81, 81, 81, 66, 66, 66, 66, 66, 73, 81, 81, // Character 'u', entry 85
 81, 81, 81, 81, 54, 54, 19, 19, 16, 16, 81, 81, // Character 'v', entry 86
 81, 81, 81, 81, 84, 84, 18, 18, 79, 79, 81, 81, // Character 'w', entry 87
 81, 81, 81, 81, 54, 19, 16, 16, 19, 54, 81, 81, // Character 'x', entry 88
 81, 81, 81, 81, 54, 54, 54, 19, 19, 16, 16, 43, // Character 'y', entry 89
 81, 81, 81, 81, 96, 12, 16, 98, 64, 96, 81, 81, // Character 'z', entry 90
 81, 16, 98, 98, 98, 98, 64, 98, 98, 98, 98, 16, // Character '{', entry 91
 81, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, // Character '|', entry 92
 81, 98, 16, 16, 16, 16, 12, 16, 16, 16, 16, 98, // Character '}', entry 93
 81, 81, 34, 29, 81, 81, 81, 81, 81, 81, 81, 81, // Character '~', entry 94
 81, 81, 81, 81, 15, 15, 15, 66, 66, 52, 64, 64, // Character 'µ', entry 95
 16, 12, 16, 16, 19, 19, 54, 44, 54, 54, 81, 81, // Character 'À', entry 96
 16, 98, 16, 16, 19, 19, 54, 44, 54, 54, 81, 81, // Character 'Á', entry 97
 81, 81, 42, 2, 79, 25, 28, 66, 54, 49, 81, 81, // Character 'Æ', entry 98
 81, 81, 26, 54, 64, 64, 64, 64, 54, 26, 16, 98, // Character 'Ç', entry 99
 16, 12, 28, 98, 98, 26, 98, 98, 98, 28, 81, 81, // Character 'È', entry 100
 12, 16, 28, 98, 98, 26, 98, 98, 98, 28, 81, 81, // Character 'É', entry 101
 16, 19, 28, 98, 98, 26, 98, 98, 98, 28, 81, 81, // Character 'Ê', entry 102
 66, 81, 28, 98, 98, 26, 98, 98, 98, 28, 81, 81, // Character 'Ë', entry 103
 81, 98, 16, 81, 4, 68, 26, 68, 68, 26, 81, 81, // Character 'à', entry 104
 81, 16, 98, 81, 4, 68, 26, 68, 68, 26, 81, 81, // Character 'á', entry 105
 81, 4, 68, 81, 4, 68, 26, 68, 68, 26, 81, 81, // Character 'â', entry 106
 81, 97, 76, 81, 4, 68, 26, 68, 68, 26, 81, 81, // Character 'ã', entry 107
 81, 81, 19, 81, 4, 68, 26, 68, 68, 26, 81, 81, // Character 'ä', entry 108
 81, 16, 19, 16, 4, 68, 26, 68, 68, 26, 81, 81, // Character 'å', entry 109
 81, 81, 81, 81, 56, 31, 58, 68, 31, 56, 81, 81, // Character 'æ', entry 110
 81, 81, 81, 81, 4, 68, 64, 64, 68, 4, 16, 98, // Character 'ç', entry 111
 81, 98, 16, 81, 4, 68, 96, 64, 68, 4, 81, 81, // Character 'è', entry 112
 81, 16, 98, 81, 4, 68, 96, 64, 68, 4, 81, 81, // Character 'é', entry 113
 81, 4, 68, 81, 4, 68, 96, 64, 68, 4, 81, 81, // Character 'ê', entry 114
 81, 81, 68, 81, 4, 68, 96, 64, 68, 4, 81, 81, // Character 'ë', entry 115
 81, 16, 12, 81, 66, 66, 66, 66, 66, 73, 81, 81, // Character 'ù', entry 116
 81, 12, 16, 81, 66, 66, 66, 66, 66, 73, 81, 81, // Character 'ú', entry 117
 81, 30, 66, 81, 66, 66, 66, 66, 66, 73, 81, 81, // Character 'û', entry 118
 81, 81, 66, 81, 66, 66, 66, 66, 66, 73, 81, 81, // Character 'ü', entry 119
 81, 81, 36, 54, 54, 21, 54, 54, 54, 36, 81, 81, // Character 'Œ', entry 120
 81, 81, 81, 81, 56, 31, 74, 68, 31, 56, 81, 81, // Character 'œ', entry 121
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const AWFontInternalDefinition Geneva10 = {
  10, // Font size
  10, // Ascender
  -1, // Descender
  7, // Range Count
  11, // Maximum Advancement
  0, // Empty Left Column Count
  9, // Column Count
  kRangeArray_Geneva10,
  kAdvancementArray_Geneva10,
  kHorizontalSegmentArray_Geneva10,
  kCharacterSegmentIndexArray8_Geneva10,
  NULL,
  "Geneva" // Font Name
} ; // 1741 bytes

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————


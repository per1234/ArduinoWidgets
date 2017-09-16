#include "AWFont-Geneva12.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint32_t kRangeArray_Geneva12 [14] = {
 0x20,  0x7E,
 0xB5,  0xB5,
 0xC0,  0xC1,
 0xC6,  0xCB,
 0xE0,  0xEB,
 0xF9,  0xFC,
 0x152,  0x153
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint8_t kAdvancementArray_Geneva12 [122] = {
  4, // Character ' ', entry 0
  4, // Character '!', entry 1
  6, // Character '"', entry 2
  8, // Character '#', entry 3
  8, // Character '$', entry 4
  11, // Character '%', entry 5
  9, // Character '&', entry 6
  4, // Character ''', entry 7
  5, // Character '(', entry 8
  5, // Character ')', entry 9
  6, // Character '*', entry 10
  8, // Character '+', entry 11
  4, // Character ',', entry 12
  5, // Character '-', entry 13
  4, // Character '.', entry 14
  6, // Character '/', entry 15
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
  8, // Character '<', entry 28
  8, // Character '=', entry 29
  8, // Character '>', entry 30
  7, // Character '?', entry 31
  10, // Character '@', entry 32
  9, // Character 'A', entry 33
  8, // Character 'B', entry 34
  8, // Character 'C', entry 35
  8, // Character 'D', entry 36
  7, // Character 'E', entry 37
  7, // Character 'F', entry 38
  8, // Character 'G', entry 39
  8, // Character 'H', entry 40
  3, // Character 'I', entry 41
  6, // Character 'J', entry 42
  8, // Character 'K', entry 43
  7, // Character 'L', entry 44
  9, // Character 'M', entry 45
  9, // Character 'N', entry 46
  9, // Character 'O', entry 47
  7, // Character 'P', entry 48
  9, // Character 'Q', entry 49
  7, // Character 'R', entry 50
  7, // Character 'S', entry 51
  8, // Character 'T', entry 52
  8, // Character 'U', entry 53
  9, // Character 'V', entry 54
  11, // Character 'W', entry 55
  7, // Character 'X', entry 56
  7, // Character 'Y', entry 57
  7, // Character 'Z', entry 58
  5, // Character '[', entry 59
  6, // Character '\', entry 60
  5, // Character ']', entry 61
  8, // Character '^', entry 62
  8, // Character '_', entry 63
  7, // Character '`', entry 64
  7, // Character 'a', entry 65
  7, // Character 'b', entry 66
  7, // Character 'c', entry 67
  7, // Character 'd', entry 68
  7, // Character 'e', entry 69
  5, // Character 'f', entry 70
  7, // Character 'g', entry 71
  7, // Character 'h', entry 72
  3, // Character 'i', entry 73
  3, // Character 'j', entry 74
  6, // Character 'k', entry 75
  3, // Character 'l', entry 76
  11, // Character 'm', entry 77
  7, // Character 'n', entry 78
  7, // Character 'o', entry 79
  7, // Character 'p', entry 80
  7, // Character 'q', entry 81
  5, // Character 'r', entry 82
  6, // Character 's', entry 83
  5, // Character 't', entry 84
  7, // Character 'u', entry 85
  7, // Character 'v', entry 86
  9, // Character 'w', entry 87
  6, // Character 'x', entry 88
  7, // Character 'y', entry 89
  7, // Character 'z', entry 90
  5, // Character '{', entry 91
  3, // Character '|', entry 92
  5, // Character '}', entry 93
  8, // Character '~', entry 94
  7, // Character 'µ', entry 95
  9, // Character 'À', entry 96
  9, // Character 'Á', entry 97
  12, // Character 'Æ', entry 98
  8, // Character 'Ç', entry 99
  7, // Character 'È', entry 100
  7, // Character 'É', entry 101
  7, // Character 'Ê', entry 102
  7, // Character 'Ë', entry 103
  7, // Character 'à', entry 104
  7, // Character 'á', entry 105
  7, // Character 'â', entry 106
  7, // Character 'ã', entry 107
  7, // Character 'ä', entry 108
  7, // Character 'å', entry 109
  11, // Character 'æ', entry 110
  7, // Character 'ç', entry 111
  7, // Character 'è', entry 112
  7, // Character 'é', entry 113
  7, // Character 'ê', entry 114
  7, // Character 'ë', entry 115
  7, // Character 'ù', entry 116
  7, // Character 'ú', entry 117
  7, // Character 'û', entry 118
  7, // Character 'ü', entry 119
  13, // Character 'Œ', entry 120
  12, // Character 'œ', entry 121
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint8_t kHorizontalSegmentArray_Geneva12 [115] = {
 0x15, 0x34, // Index 0
 0x15, 0x25, 0x22, // Index 2
 0x4, // Index 5
 0x1C, // Index 6
 0x13, 0x3A, // Index 7
 0x13, 0x15, 0x24, // Index 9
 0x23, 0x42, // Index 12
 0x3, 0x33, 0x12, // Index 14
 0xE, // Index 17
 0x13, 0x4A, // Index 18
 0x0, // Index 20
 0x13, 0x42, // Index 21
 0x13, 0x72, // Index 23
 0x13, 0x24, // Index 25
 0x13, 0x13, 0x22, // Index 27
 0x53, 0x32, // Index 30
 0x5C, // Index 32
 0x38, // Index 33
 0x13, 0x32, // Index 34
 0x13, 0x52, // Index 36
 0x54, // Index 38
 0x2C, // Index 39
 0x33, 0x14, // Index 40
 0x3, 0x42, // Index 42
 0x13, 0x33, 0x32, // Index 44
 0x13, 0x27, 0x12, // Index 47
 0x13, 0x13, 0x23, 0x12, // Index 50
 0x2F, 0x2, // Index 54
 0x36, // Index 56
 0x62, // Index 57
 0x23, 0x13, 0x22, // Index 58
 0x15, 0x32, // Index 61
 0x13, 0x28, // Index 63
 0x1E, // Index 65
 0x13, 0x14, // Index 66
 0x15, 0x22, // Index 68
 0x3E, // Index 70
 0x17, 0x32, // Index 71
 0x43, 0x12, // Index 73
 0x23, 0x13, 0x13, 0x12, // Index 75
 0x13, 0x48, // Index 79
 0x27, 0x16, // Index 81
 0x13, 0x34, // Index 83
 0x13, 0x26, // Index 85
 0x19, 0x12, // Index 87
 0x25, 0x12, // Index 89
 0x23, 0x32, // Index 91
 0x13, 0x13, 0x13, 0x12, // Index 93
 0x1A, // Index 97
 0xF, 0x2, // Index 98
 0x13, 0x23, 0x22, // Index 100
 0x3, 0x12, // Index 103
 0x23, 0x23, 0x22, // Index 105
 0x13, 0x16, // Index 108
 0x33, 0x22, // Index 110
 0x29, 0x18, // Index 112
 0x2A, // Index 114
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const uint8_t kCharacterSegmentIndexArray8_Geneva12 [1830] = {
 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, // Character ' ', entry 0
 20, 20, 20, 16, 16, 16, 16, 16, 16, 16, 20, 16, 20, 20, 20, // Character '!', entry 1
 20, 20, 20, 77, 77, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, // Character '"', entry 2
 20, 20, 20, 73, 39, 15, 6, 52, 20, 20, 20, 20, 20, 20, 20, // Character '#', entry 3
 20, 20, 31, 86, 76, 77, 11, 1, 15, 15, 76, 86, 31, 20, 20, // Character '$', entry 4
 20, 20, 20, 39, 100, 51, 89, 13, 40, 58, 100, 83, 20, 20, 20, // Character '%', entry 5
 20, 20, 20, 11, 28, 77, 4, 77, 14, 42, 14, 71, 20, 20, 20, // Character '&', entry 6
 20, 20, 20, 16, 16, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, // Character ''', entry 7
 20, 20, 31, 4, 4, 16, 16, 16, 16, 16, 4, 4, 31, 20, 20, // Character '(', entry 8
 20, 20, 16, 4, 4, 31, 31, 31, 31, 31, 4, 4, 16, 20, 20, // Character ')', entry 9
 20, 20, 20, 20, 31, 76, 86, 52, 34, 20, 20, 20, 20, 20, 20, // Character '*', entry 10
 20, 20, 20, 20, 20, 31, 31, 97, 31, 31, 20, 20, 20, 20, 20, // Character '+', entry 11
 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 4, 4, 16, 20, // Character ',', entry 12
 20, 20, 20, 20, 20, 20, 20, 97, 20, 20, 20, 20, 20, 20, 20, // Character '-', entry 13
 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 16, 20, 20, 20, // Character '.', entry 14
 20, 20, 37, 37, 13, 13, 31, 31, 4, 4, 16, 16, 20, 20, 20, // Character '/', entry 15
 20, 20, 20, 1, 101, 21, 21, 21, 21, 21, 101, 1, 20, 20, 20, // Character '0', entry 16
 20, 20, 20, 13, 1, 13, 13, 13, 13, 13, 13, 13, 20, 20, 20, // Character '1', entry 17
 20, 20, 20, 56, 91, 21, 57, 37, 13, 31, 4, 6, 20, 20, 20, // Character '2', entry 18
 20, 20, 20, 6, 37, 13, 1, 37, 57, 57, 34, 86, 20, 20, 20, // Character '3', entry 19
 20, 20, 20, 57, 38, 73, 110, 91, 21, 65, 57, 57, 20, 20, 20, // Character '4', entry 20
 20, 20, 20, 6, 16, 16, 97, 57, 57, 57, 21, 64, 20, 20, 20, // Character '5', entry 21
 20, 20, 20, 56, 4, 16, 97, 21, 21, 21, 21, 64, 20, 20, 20, // Character '6', entry 22
 20, 20, 20, 6, 57, 37, 37, 13, 13, 31, 31, 31, 20, 20, 20, // Character '7', entry 23
 20, 20, 20, 64, 21, 21, 64, 21, 21, 21, 21, 64, 20, 20, 20, // Character '8', entry 24
 20, 20, 20, 64, 21, 21, 21, 21, 114, 57, 37, 86, 20, 20, 20, // Character '9', entry 25
 20, 20, 20, 20, 20, 20, 16, 20, 20, 20, 20, 16, 20, 20, 20, // Character ':', entry 26
 20, 20, 20, 20, 20, 20, 4, 20, 20, 20, 20, 4, 4, 16, 20, // Character ';', entry 27
 20, 20, 20, 20, 20, 13, 31, 4, 16, 4, 31, 13, 20, 20, 20, // Character '<', entry 28
 20, 20, 20, 20, 20, 20, 20, 97, 20, 20, 97, 20, 20, 20, 20, // Character '=', entry 29
 20, 20, 20, 20, 20, 16, 4, 31, 13, 31, 4, 16, 20, 20, 20, // Character '>', entry 30
 20, 20, 20, 64, 21, 21, 37, 13, 31, 31, 20, 31, 20, 20, 20, // Character '?', entry 31
 20, 20, 20, 20, 33, 12, 47, 50, 50, 63, 4, 56, 20, 20, 20, // Character '@', entry 32
 20, 20, 20, 13, 13, 15, 15, 91, 91, 65, 36, 36, 20, 20, 20, // Character 'A', entry 33
 20, 20, 20, 97, 21, 21, 97, 21, 21, 21, 21, 97, 20, 20, 20, // Character 'B', entry 34
 20, 20, 20, 64, 21, 16, 16, 16, 16, 16, 21, 64, 20, 20, 20, // Character 'C', entry 35
 20, 20, 20, 113, 34, 21, 21, 21, 21, 21, 34, 113, 20, 20, 20, // Character 'D', entry 36
 20, 20, 20, 97, 16, 16, 16, 113, 16, 16, 16, 97, 20, 20, 20, // Character 'E', entry 37
 20, 20, 20, 97, 16, 16, 16, 113, 16, 16, 16, 16, 20, 20, 20, // Character 'F', entry 38
 20, 20, 20, 64, 21, 16, 16, 85, 21, 21, 21, 64, 20, 20, 20, // Character 'G', entry 39
 20, 20, 20, 21, 21, 21, 21, 6, 21, 21, 21, 21, 20, 20, 20, // Character 'H', entry 40
 20, 20, 20, 4, 4, 4, 4, 4, 4, 4, 4, 4, 20, 20, 20, // Character 'I', entry 41
 20, 20, 20, 37, 37, 37, 37, 37, 37, 42, 42, 113, 20, 20, 20, // Character 'J', entry 42
 20, 20, 20, 21, 34, 28, 77, 41, 77, 28, 34, 21, 20, 20, 20, // Character 'K', entry 43
 20, 20, 20, 16, 16, 16, 16, 16, 16, 16, 16, 97, 20, 20, 20, // Character 'L', entry 44
 20, 20, 20, 36, 0, 93, 100, 36, 36, 36, 36, 36, 20, 20, 20, // Character 'M', entry 45
 20, 20, 20, 61, 61, 27, 27, 51, 51, 83, 83, 21, 20, 20, 20, // Character 'N', entry 46
 20, 20, 20, 64, 21, 21, 21, 21, 21, 21, 21, 64, 20, 20, 20, // Character 'O', entry 47
 20, 20, 20, 97, 21, 21, 21, 97, 16, 16, 16, 16, 20, 20, 20, // Character 'P', entry 48
 20, 20, 20, 64, 21, 21, 21, 21, 21, 21, 21, 64, 13, 38, 20, // Character 'Q', entry 49
 20, 20, 20, 97, 21, 21, 21, 97, 28, 34, 21, 21, 20, 20, 20, // Character 'R', entry 50
 20, 20, 20, 64, 21, 16, 16, 64, 57, 57, 21, 64, 20, 20, 20, // Character 'S', entry 51
 20, 20, 20, 17, 31, 31, 31, 31, 31, 31, 31, 31, 20, 20, 20, // Character 'T', entry 52
 20, 20, 20, 21, 21, 21, 21, 21, 21, 21, 21, 64, 20, 20, 20, // Character 'U', entry 53
 20, 20, 20, 36, 36, 36, 91, 91, 15, 15, 13, 13, 20, 20, 20, // Character 'V', entry 54
 20, 20, 20, 23, 23, 44, 105, 75, 75, 45, 45, 45, 20, 20, 20, // Character 'W', entry 55
 20, 20, 20, 34, 34, 52, 52, 31, 52, 52, 34, 34, 20, 20, 20, // Character 'X', entry 56
 20, 20, 20, 34, 34, 34, 52, 52, 31, 31, 31, 31, 20, 20, 20, // Character 'Y', entry 57
 20, 20, 20, 97, 37, 13, 13, 31, 4, 4, 16, 97, 20, 20, 20, // Character 'Z', entry 58
 20, 20, 41, 16, 16, 16, 16, 16, 16, 16, 16, 16, 41, 20, 20, // Character '[', entry 59
 20, 20, 16, 16, 4, 4, 31, 31, 13, 13, 37, 37, 20, 20, 20, // Character '\', entry 60
 20, 20, 41, 4, 4, 4, 4, 4, 4, 4, 4, 4, 41, 20, 20, // Character ']', entry 61
 20, 20, 20, 16, 16, 103, 103, 20, 20, 20, 20, 20, 20, 20, 20, // Character '^', entry 62
 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 98, 20, 20, 20, // Character '_', entry 63
 20, 20, 20, 16, 4, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, // Character '`', entry 64
 20, 20, 20, 20, 20, 86, 34, 37, 64, 34, 34, 64, 20, 20, 20, // Character 'a', entry 65
 20, 20, 20, 16, 16, 113, 34, 34, 34, 34, 34, 113, 20, 20, 20, // Character 'b', entry 66
 20, 20, 20, 20, 20, 86, 34, 16, 16, 16, 34, 86, 20, 20, 20, // Character 'c', entry 67
 20, 20, 20, 37, 37, 64, 34, 34, 34, 34, 34, 64, 20, 20, 20, // Character 'd', entry 68
 20, 20, 20, 20, 20, 86, 34, 34, 97, 16, 34, 86, 20, 20, 20, // Character 'e', entry 69
 20, 20, 20, 1, 4, 82, 4, 4, 4, 4, 4, 4, 20, 20, 20, // Character 'f', entry 70
 20, 20, 20, 20, 20, 64, 34, 34, 34, 34, 34, 64, 37, 34, 86, // Character 'g', entry 71
 20, 20, 20, 16, 16, 66, 68, 34, 34, 34, 34, 34, 20, 20, 20, // Character 'h', entry 72
 20, 20, 20, 4, 20, 4, 4, 4, 4, 4, 4, 4, 20, 20, 20, // Character 'i', entry 73
 20, 20, 20, 31, 20, 31, 31, 31, 31, 31, 31, 31, 31, 31, 41, // Character 'j', entry 74
 20, 20, 20, 16, 16, 34, 28, 77, 41, 77, 28, 34, 20, 20, 20, // Character 'k', entry 75
 20, 20, 20, 4, 4, 4, 4, 4, 4, 4, 4, 4, 20, 20, 20, // Character 'l', entry 76
 20, 20, 20, 20, 20, 9, 2, 44, 44, 44, 44, 44, 20, 20, 20, // Character 'm', entry 77
 20, 20, 20, 20, 20, 66, 68, 34, 34, 34, 34, 34, 20, 20, 20, // Character 'n', entry 78
 20, 20, 20, 20, 20, 86, 34, 34, 34, 34, 34, 86, 20, 20, 20, // Character 'o', entry 79
 20, 20, 20, 20, 20, 113, 34, 34, 34, 34, 34, 113, 16, 16, 20, // Character 'p', entry 80
 20, 20, 20, 20, 20, 64, 34, 34, 34, 34, 34, 64, 37, 37, 20, // Character 'q', entry 81
 20, 20, 20, 20, 20, 108, 41, 16, 16, 16, 16, 16, 20, 20, 20, // Character 'r', entry 82
 20, 20, 20, 20, 20, 86, 34, 16, 86, 37, 34, 86, 20, 20, 20, // Character 's', entry 83
 20, 20, 20, 4, 4, 82, 4, 4, 4, 4, 4, 1, 20, 20, 20, // Character 't', entry 84
 20, 20, 20, 20, 20, 34, 34, 34, 34, 34, 25, 89, 20, 20, 20, // Character 'u', entry 85
 20, 20, 20, 20, 20, 34, 34, 34, 52, 52, 31, 31, 20, 20, 20, // Character 'v', entry 86
 20, 20, 20, 20, 20, 44, 44, 75, 75, 45, 45, 45, 20, 20, 20, // Character 'w', entry 87
 20, 20, 20, 20, 20, 34, 34, 52, 31, 52, 34, 34, 20, 20, 20, // Character 'x', entry 88
 20, 20, 20, 20, 20, 34, 34, 34, 52, 52, 31, 31, 4, 4, 5, // Character 'y', entry 89
 20, 20, 20, 20, 20, 97, 37, 13, 31, 4, 16, 97, 20, 20, 20, // Character 'z', entry 90
 20, 20, 31, 4, 4, 4, 4, 16, 4, 4, 4, 4, 31, 20, 20, // Character '{', entry 91
 20, 20, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 20, 20, // Character '|', entry 92
 20, 20, 16, 4, 4, 4, 4, 31, 4, 4, 4, 4, 16, 20, 20, // Character '}', entry 93
 20, 20, 20, 3, 25, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, // Character '~', entry 94
 20, 20, 20, 20, 20, 45, 45, 91, 91, 91, 34, 87, 55, 55, 20, // Character 'µ', entry 95
 31, 13, 20, 13, 13, 15, 15, 91, 91, 65, 36, 36, 20, 20, 20, // Character 'À', entry 96
 37, 13, 20, 13, 13, 15, 15, 91, 91, 65, 36, 36, 20, 20, 20, // Character 'Á', entry 97
 20, 20, 20, 32, 73, 73, 110, 70, 91, 91, 21, 18, 20, 20, 20, // Character 'Æ', entry 98
 20, 20, 20, 64, 21, 16, 16, 16, 16, 16, 21, 64, 13, 37, 13, // Character 'Ç', entry 99
 4, 31, 20, 97, 16, 16, 16, 113, 16, 16, 16, 97, 20, 20, 20, // Character 'È', entry 100
 13, 31, 20, 97, 16, 16, 16, 113, 16, 16, 16, 97, 20, 20, 20, // Character 'É', entry 101
 31, 52, 20, 97, 16, 16, 16, 113, 16, 16, 16, 97, 20, 20, 20, // Character 'Ê', entry 102
 20, 52, 20, 97, 16, 16, 16, 113, 16, 16, 16, 97, 20, 20, 20, // Character 'Ë', entry 103
 20, 20, 31, 13, 20, 86, 34, 64, 34, 34, 34, 64, 20, 20, 20, // Character 'à', entry 104
 20, 20, 31, 4, 20, 86, 34, 64, 34, 34, 34, 64, 20, 20, 20, // Character 'á', entry 105
 20, 20, 31, 52, 20, 86, 34, 64, 34, 34, 34, 64, 20, 20, 20, // Character 'â', entry 106
 20, 20, 89, 66, 20, 86, 34, 64, 34, 34, 34, 64, 20, 20, 20, // Character 'ã', entry 107
 20, 20, 20, 52, 20, 86, 34, 64, 34, 34, 34, 64, 20, 20, 20, // Character 'ä', entry 108
 11, 28, 28, 11, 20, 86, 34, 64, 34, 34, 34, 64, 20, 20, 20, // Character 'å', entry 109
 20, 20, 20, 20, 20, 81, 44, 30, 54, 34, 44, 81, 20, 20, 20, // Character 'æ', entry 110
 20, 20, 20, 20, 20, 86, 34, 16, 16, 16, 34, 86, 31, 4, 20, // Character 'ç', entry 111
 20, 20, 4, 31, 20, 86, 34, 34, 97, 16, 34, 86, 20, 20, 20, // Character 'è', entry 112
 20, 20, 31, 4, 20, 86, 34, 34, 97, 16, 34, 86, 20, 20, 20, // Character 'é', entry 113
 20, 20, 31, 52, 20, 86, 34, 34, 97, 16, 34, 86, 20, 20, 20, // Character 'ê', entry 114
 20, 20, 20, 52, 20, 86, 34, 34, 97, 16, 34, 86, 20, 20, 20, // Character 'ë', entry 115
 20, 20, 4, 31, 20, 34, 34, 34, 34, 34, 25, 89, 20, 20, 20, // Character 'ù', entry 116
 20, 20, 13, 31, 20, 34, 34, 34, 34, 34, 25, 89, 20, 20, 20, // Character 'ú', entry 117
 20, 20, 31, 52, 20, 34, 34, 34, 34, 34, 25, 89, 20, 20, 20, // Character 'û', entry 118
 20, 20, 20, 52, 20, 34, 34, 34, 34, 34, 25, 89, 20, 20, 20, // Character 'ü', entry 119
 20, 20, 20, 112, 21, 21, 21, 79, 21, 21, 21, 112, 20, 20, 20, // Character 'Œ', entry 120
 20, 20, 20, 20, 20, 81, 44, 44, 7, 34, 44, 81, 20, 20, 20, // Character 'œ', entry 121
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const AWFontInternalDefinition Geneva12 = {
  12, // Font size
  11, // Ascender
  -3, // Descender
  7, // Range Count
  13, // Maximum Advancement
  0, // Empty Left Column Count
  11, // Column Count
  kRangeArray_Geneva12,
  kAdvancementArray_Geneva12,
  kHorizontalSegmentArray_Geneva12,
  kCharacterSegmentIndexArray8_Geneva12,
  NULL,
  "Geneva" // Font Name
} ; // 2123 bytes

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————


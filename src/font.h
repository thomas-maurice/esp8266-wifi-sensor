// Created by http://oleddisplay.squix.ch/ Consider a donation
// In case of problems make sure that you are using the font file with the correct version!
const uint8_t Cousine_Regular_10[] PROGMEM = {
	0x06, // Width: 6
	0x0C, // Height: 12
	0x20, // First Char: 32
	0xE0, // Numbers of Chars: 224

	// Jump Table:
	0xFF, 0xFF, 0x00, 0x06,  // 32:65535
	0x00, 0x00, 0x07, 0x06,  // 33:0
	0x00, 0x07, 0x09, 0x06,  // 34:7
	0x00, 0x10, 0x0B, 0x06,  // 35:16
	0x00, 0x1B, 0x0B, 0x06,  // 36:27
	0x00, 0x26, 0x0C, 0x06,  // 37:38
	0x00, 0x32, 0x0C, 0x06,  // 38:50
	0x00, 0x3E, 0x07, 0x06,  // 39:62
	0x00, 0x45, 0x08, 0x06,  // 40:69
	0x00, 0x4D, 0x08, 0x06,  // 41:77
	0x00, 0x55, 0x09, 0x06,  // 42:85
	0x00, 0x5E, 0x09, 0x06,  // 43:94
	0x00, 0x67, 0x06, 0x06,  // 44:103
	0x00, 0x6D, 0x07, 0x06,  // 45:109
	0x00, 0x74, 0x08, 0x06,  // 46:116
	0x00, 0x7C, 0x09, 0x06,  // 47:124
	0x00, 0x85, 0x09, 0x06,  // 48:133
	0x00, 0x8E, 0x0C, 0x06,  // 49:142
	0x00, 0x9A, 0x0A, 0x06,  // 50:154
	0x00, 0xA4, 0x0A, 0x06,  // 51:164
	0x00, 0xAE, 0x0B, 0x06,  // 52:174
	0x00, 0xB9, 0x09, 0x06,  // 53:185
	0x00, 0xC2, 0x0A, 0x06,  // 54:194
	0x00, 0xCC, 0x09, 0x06,  // 55:204
	0x00, 0xD5, 0x0A, 0x06,  // 56:213
	0x00, 0xDF, 0x09, 0x06,  // 57:223
	0x00, 0xE8, 0x08, 0x06,  // 58:232
	0x00, 0xF0, 0x08, 0x06,  // 59:240
	0x00, 0xF8, 0x09, 0x06,  // 60:248
	0x01, 0x01, 0x09, 0x06,  // 61:257
	0x01, 0x0A, 0x09, 0x06,  // 62:266
	0x01, 0x13, 0x09, 0x06,  // 63:275
	0x01, 0x1C, 0x0B, 0x06,  // 64:284
	0x01, 0x27, 0x0C, 0x06,  // 65:295
	0x01, 0x33, 0x0B, 0x06,  // 66:307
	0x01, 0x3E, 0x0B, 0x06,  // 67:318
	0x01, 0x49, 0x0B, 0x06,  // 68:329
	0x01, 0x54, 0x0A, 0x06,  // 69:340
	0x01, 0x5E, 0x09, 0x06,  // 70:350
	0x01, 0x67, 0x0A, 0x06,  // 71:359
	0x01, 0x71, 0x0A, 0x06,  // 72:369
	0x01, 0x7B, 0x0A, 0x06,  // 73:379
	0x01, 0x85, 0x09, 0x06,  // 74:389
	0x01, 0x8E, 0x0C, 0x06,  // 75:398
	0x01, 0x9A, 0x0A, 0x06,  // 76:410
	0x01, 0xA4, 0x0A, 0x06,  // 77:420
	0x01, 0xAE, 0x0A, 0x06,  // 78:430
	0x01, 0xB8, 0x0B, 0x06,  // 79:440
	0x01, 0xC3, 0x09, 0x06,  // 80:451
	0x01, 0xCC, 0x0C, 0x06,  // 81:460
	0x01, 0xD8, 0x0A, 0x06,  // 82:472
	0x01, 0xE2, 0x0A, 0x06,  // 83:482
	0x01, 0xEC, 0x0B, 0x06,  // 84:492
	0x01, 0xF7, 0x0A, 0x06,  // 85:503
	0x02, 0x01, 0x0B, 0x06,  // 86:513
	0x02, 0x0C, 0x0B, 0x06,  // 87:524
	0x02, 0x17, 0x0C, 0x06,  // 88:535
	0x02, 0x23, 0x0B, 0x06,  // 89:547
	0x02, 0x2E, 0x0C, 0x06,  // 90:558
	0x02, 0x3A, 0x0A, 0x06,  // 91:570
	0x02, 0x44, 0x0A, 0x06,  // 92:580
	0x02, 0x4E, 0x08, 0x06,  // 93:590
	0x02, 0x56, 0x09, 0x06,  // 94:598
	0x02, 0x5F, 0x0C, 0x06,  // 95:607
	0x02, 0x6B, 0x07, 0x06,  // 96:619
	0x02, 0x72, 0x0C, 0x06,  // 97:626
	0x02, 0x7E, 0x0A, 0x06,  // 98:638
	0x02, 0x88, 0x0A, 0x06,  // 99:648
	0x02, 0x92, 0x0A, 0x06,  // 100:658
	0x02, 0x9C, 0x0A, 0x06,  // 101:668
	0x02, 0xA6, 0x09, 0x06,  // 102:678
	0x02, 0xAF, 0x0A, 0x06,  // 103:687
	0x02, 0xB9, 0x0A, 0x06,  // 104:697
	0x02, 0xC3, 0x0C, 0x06,  // 105:707
	0x02, 0xCF, 0x08, 0x06,  // 106:719
	0x02, 0xD7, 0x0A, 0x06,  // 107:727
	0x02, 0xE1, 0x0A, 0x06,  // 108:737
	0x02, 0xEB, 0x0A, 0x06,  // 109:747
	0x02, 0xF5, 0x0A, 0x06,  // 110:757
	0x02, 0xFF, 0x0A, 0x06,  // 111:767
	0x03, 0x09, 0x0A, 0x06,  // 112:777
	0x03, 0x13, 0x0A, 0x06,  // 113:787
	0x03, 0x1D, 0x09, 0x06,  // 114:797
	0x03, 0x26, 0x0A, 0x06,  // 115:806
	0x03, 0x30, 0x0A, 0x06,  // 116:816
	0x03, 0x3A, 0x0A, 0x06,  // 117:826
	0x03, 0x44, 0x09, 0x06,  // 118:836
	0x03, 0x4D, 0x0B, 0x06,  // 119:845
	0x03, 0x58, 0x0A, 0x06,  // 120:856
	0x03, 0x62, 0x09, 0x06,  // 121:866
	0x03, 0x6B, 0x0A, 0x06,  // 122:875
	0x03, 0x75, 0x0A, 0x06,  // 123:885
	0x03, 0x7F, 0x06, 0x06,  // 124:895
	0x03, 0x85, 0x09, 0x06,  // 125:901
	0x03, 0x8E, 0x09, 0x06,  // 126:910
	0x03, 0x97, 0x08, 0x06,  // 127:919
	0x03, 0x9F, 0x08, 0x06,  // 128:927
	0x03, 0xA7, 0x08, 0x06,  // 129:935
	0x03, 0xAF, 0x08, 0x06,  // 130:943
	0x03, 0xB7, 0x08, 0x06,  // 131:951
	0x03, 0xBF, 0x08, 0x06,  // 132:959
	0x03, 0xC7, 0x08, 0x06,  // 133:967
	0x03, 0xCF, 0x08, 0x06,  // 134:975
	0x03, 0xD7, 0x08, 0x06,  // 135:983
	0x03, 0xDF, 0x08, 0x06,  // 136:991
	0x03, 0xE7, 0x08, 0x06,  // 137:999
	0x03, 0xEF, 0x08, 0x06,  // 138:1007
	0x03, 0xF7, 0x08, 0x06,  // 139:1015
	0x03, 0xFF, 0x08, 0x06,  // 140:1023
	0x04, 0x07, 0x08, 0x06,  // 141:1031
	0x04, 0x0F, 0x08, 0x06,  // 142:1039
	0x04, 0x17, 0x08, 0x06,  // 143:1047
	0x04, 0x1F, 0x08, 0x06,  // 144:1055
	0x04, 0x27, 0x08, 0x06,  // 145:1063
	0x04, 0x2F, 0x08, 0x06,  // 146:1071
	0x04, 0x37, 0x08, 0x06,  // 147:1079
	0x04, 0x3F, 0x08, 0x06,  // 148:1087
	0x04, 0x47, 0x08, 0x06,  // 149:1095
	0x04, 0x4F, 0x08, 0x06,  // 150:1103
	0x04, 0x57, 0x08, 0x06,  // 151:1111
	0x04, 0x5F, 0x08, 0x06,  // 152:1119
	0x04, 0x67, 0x08, 0x06,  // 153:1127
	0x04, 0x6F, 0x08, 0x06,  // 154:1135
	0x04, 0x77, 0x08, 0x06,  // 155:1143
	0x04, 0x7F, 0x08, 0x06,  // 156:1151
	0x04, 0x87, 0x08, 0x06,  // 157:1159
	0x04, 0x8F, 0x08, 0x06,  // 158:1167
	0x04, 0x97, 0x08, 0x06,  // 159:1175
	0xFF, 0xFF, 0x00, 0x06,  // 160:65535
	0x04, 0x9F, 0x07, 0x06,  // 161:1183
	0x04, 0xA6, 0x09, 0x06,  // 162:1190
	0x04, 0xAF, 0x0C, 0x06,  // 163:1199
	0x04, 0xBB, 0x09, 0x06,  // 164:1211
	0x04, 0xC4, 0x09, 0x06,  // 165:1220
	0x04, 0xCD, 0x06, 0x06,  // 166:1229
	0x04, 0xD3, 0x0A, 0x06,  // 167:1235
	0x04, 0xDD, 0x07, 0x06,  // 168:1245
	0x04, 0xE4, 0x0B, 0x06,  // 169:1252
	0x04, 0xEF, 0x09, 0x06,  // 170:1263
	0x04, 0xF8, 0x09, 0x06,  // 171:1272
	0x05, 0x01, 0x09, 0x06,  // 172:1281
	0x05, 0x0A, 0x07, 0x06,  // 173:1290
	0x05, 0x11, 0x0B, 0x06,  // 174:1297
	0x05, 0x1C, 0x0B, 0x06,  // 175:1308
	0x05, 0x27, 0x07, 0x06,  // 176:1319
	0x05, 0x2E, 0x0A, 0x06,  // 177:1326
	0x05, 0x38, 0x07, 0x06,  // 178:1336
	0x05, 0x3F, 0x09, 0x06,  // 179:1343
	0x05, 0x48, 0x07, 0x06,  // 180:1352
	0x05, 0x4F, 0x0A, 0x06,  // 181:1359
	0x05, 0x59, 0x0A, 0x06,  // 182:1369
	0x05, 0x63, 0x07, 0x06,  // 183:1379
	0x05, 0x6A, 0x04, 0x06,  // 184:1386
	0x05, 0x6E, 0x09, 0x06,  // 185:1390
	0x05, 0x77, 0x09, 0x06,  // 186:1399
	0x05, 0x80, 0x09, 0x06,  // 187:1408
	0x05, 0x89, 0x0C, 0x06,  // 188:1417
	0x05, 0x95, 0x0C, 0x06,  // 189:1429
	0x05, 0xA1, 0x0C, 0x06,  // 190:1441
	0x05, 0xAD, 0x0A, 0x06,  // 191:1453
	0x05, 0xB7, 0x0C, 0x06,  // 192:1463
	0x05, 0xC3, 0x0C, 0x06,  // 193:1475
	0x05, 0xCF, 0x0C, 0x06,  // 194:1487
	0x05, 0xDB, 0x0C, 0x06,  // 195:1499
	0x05, 0xE7, 0x0C, 0x06,  // 196:1511
	0x05, 0xF3, 0x0C, 0x06,  // 197:1523
	0x05, 0xFF, 0x0C, 0x06,  // 198:1535
	0x06, 0x0B, 0x0B, 0x06,  // 199:1547
	0x06, 0x16, 0x0A, 0x06,  // 200:1558
	0x06, 0x20, 0x0A, 0x06,  // 201:1568
	0x06, 0x2A, 0x0A, 0x06,  // 202:1578
	0x06, 0x34, 0x0A, 0x06,  // 203:1588
	0x06, 0x3E, 0x0A, 0x06,  // 204:1598
	0x06, 0x48, 0x0A, 0x06,  // 205:1608
	0x06, 0x52, 0x0A, 0x06,  // 206:1618
	0x06, 0x5C, 0x0A, 0x06,  // 207:1628
	0x06, 0x66, 0x0B, 0x06,  // 208:1638
	0x06, 0x71, 0x0A, 0x06,  // 209:1649
	0x06, 0x7B, 0x0B, 0x06,  // 210:1659
	0x06, 0x86, 0x0B, 0x06,  // 211:1670
	0x06, 0x91, 0x0B, 0x06,  // 212:1681
	0x06, 0x9C, 0x0B, 0x06,  // 213:1692
	0x06, 0xA7, 0x0B, 0x06,  // 214:1703
	0x06, 0xB2, 0x09, 0x06,  // 215:1714
	0x06, 0xBB, 0x0B, 0x06,  // 216:1723
	0x06, 0xC6, 0x0A, 0x06,  // 217:1734
	0x06, 0xD0, 0x0A, 0x06,  // 218:1744
	0x06, 0xDA, 0x0A, 0x06,  // 219:1754
	0x06, 0xE4, 0x0A, 0x06,  // 220:1764
	0x06, 0xEE, 0x0B, 0x06,  // 221:1774
	0x06, 0xF9, 0x09, 0x06,  // 222:1785
	0x07, 0x02, 0x0B, 0x06,  // 223:1794
	0x07, 0x0D, 0x0C, 0x06,  // 224:1805
	0x07, 0x19, 0x0C, 0x06,  // 225:1817
	0x07, 0x25, 0x0C, 0x06,  // 226:1829
	0x07, 0x31, 0x0C, 0x06,  // 227:1841
	0x07, 0x3D, 0x0C, 0x06,  // 228:1853
	0x07, 0x49, 0x0C, 0x06,  // 229:1865
	0x07, 0x55, 0x0C, 0x06,  // 230:1877
	0x07, 0x61, 0x0A, 0x06,  // 231:1889
	0x07, 0x6B, 0x0A, 0x06,  // 232:1899
	0x07, 0x75, 0x0A, 0x06,  // 233:1909
	0x07, 0x7F, 0x0A, 0x06,  // 234:1919
	0x07, 0x89, 0x0A, 0x06,  // 235:1929
	0x07, 0x93, 0x0C, 0x06,  // 236:1939
	0x07, 0x9F, 0x0C, 0x06,  // 237:1951
	0x07, 0xAB, 0x0C, 0x06,  // 238:1963
	0x07, 0xB7, 0x0C, 0x06,  // 239:1975
	0x07, 0xC3, 0x0A, 0x06,  // 240:1987
	0x07, 0xCD, 0x0A, 0x06,  // 241:1997
	0x07, 0xD7, 0x0A, 0x06,  // 242:2007
	0x07, 0xE1, 0x0A, 0x06,  // 243:2017
	0x07, 0xEB, 0x0A, 0x06,  // 244:2027
	0x07, 0xF5, 0x0A, 0x06,  // 245:2037
	0x07, 0xFF, 0x0A, 0x06,  // 246:2047
	0x08, 0x09, 0x09, 0x06,  // 247:2057
	0x08, 0x12, 0x0A, 0x06,  // 248:2066
	0x08, 0x1C, 0x0A, 0x06,  // 249:2076
	0x08, 0x26, 0x0A, 0x06,  // 250:2086
	0x08, 0x30, 0x0A, 0x06,  // 251:2096
	0x08, 0x3A, 0x0A, 0x06,  // 252:2106
	0x08, 0x44, 0x09, 0x06,  // 253:2116
	0x08, 0x4D, 0x0A, 0x06,  // 254:2125
	0x08, 0x57, 0x09, 0x06,  // 255:2135

	// Font Data:
	0x00,0x00,0x00,0x00,0x00,0x01,0x7C,	// 33
	0x00,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,0x1C,	// 34
	0x40,0x00,0xF0,0x01,0x5C,0x00,0xD0,0x01,0x7C,0x00,0x10,	// 35
	0x80,0x00,0x1C,0x01,0x24,0x01,0xFE,0x03,0x2C,0x01,0xC0,	// 36
	0x1C,0x00,0x94,0x01,0x5C,0x00,0xF0,0x01,0x4C,0x01,0xC0,0x01,	// 37
	0xC0,0x00,0x38,0x01,0x64,0x01,0x94,0x01,0xE8,0x01,0x00,0x01,	// 38
	0x00,0x00,0x00,0x00,0x1C,0x00,0x04,	// 39
	0x00,0x00,0x00,0x00,0xF8,0x03,0x04,0x04,	// 40
	0x00,0x00,0x00,0x00,0x04,0x04,0xF8,0x03,	// 41
	0x00,0x00,0x08,0x00,0x30,0x00,0x3C,0x00,0x08,	// 42
	0x00,0x00,0x20,0x00,0x78,0x00,0x20,0x00,0x20,	// 43
	0x00,0x00,0x00,0x04,0x00,0x03,	// 44
	0x00,0x00,0x00,0x00,0x40,0x00,0x40,	// 45
	0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x01,	// 46
	0x00,0x00,0x80,0x01,0x40,0x00,0x30,0x00,0x0C,	// 47
	0x00,0x00,0xF8,0x00,0x24,0x01,0x24,0x01,0xF8,	// 48
	0x00,0x00,0x08,0x01,0x04,0x01,0xFC,0x01,0x00,0x01,0x00,0x01,	// 49
	0x00,0x00,0x8C,0x01,0x44,0x01,0x24,0x01,0x3C,0x01,	// 50
	0x00,0x00,0x8C,0x01,0x24,0x01,0x24,0x01,0xDC,0x01,	// 51
	0x00,0x00,0x60,0x00,0x58,0x00,0x44,0x00,0xFC,0x01,0x40,	// 52
	0x00,0x00,0x9C,0x01,0x14,0x01,0x14,0x01,0xF4,	// 53
	0x00,0x00,0xF8,0x00,0x24,0x01,0x24,0x01,0xE8,0x01,	// 54
	0x00,0x00,0x04,0x00,0xC4,0x01,0x34,0x00,0x0C,	// 55
	0x00,0x00,0xDC,0x01,0x24,0x01,0x24,0x01,0xDC,0x01,	// 56
	0x00,0x00,0xBC,0x01,0x24,0x01,0x24,0x01,0xF8,	// 57
	0x00,0x00,0x00,0x00,0x10,0x01,0x10,0x01,	// 58
	0x00,0x00,0x00,0x00,0x10,0x07,0x10,0x01,	// 59
	0x00,0x00,0x20,0x00,0x50,0x00,0x50,0x00,0x88,	// 60
	0x00,0x00,0x50,0x00,0x50,0x00,0x50,0x00,0x50,	// 61
	0x00,0x00,0x88,0x00,0x50,0x00,0x50,0x00,0x20,	// 62
	0x00,0x00,0x0C,0x00,0x44,0x01,0x24,0x00,0x1C,	// 63
	0xF0,0x01,0x68,0x02,0x94,0x02,0x54,0x02,0xB4,0x02,0x78,	// 64
	0x80,0x01,0x60,0x00,0x5C,0x00,0x4C,0x00,0x70,0x00,0x80,0x01,	// 65
	0x00,0x00,0xFC,0x01,0x24,0x01,0x24,0x01,0x3C,0x01,0xC0,	// 66
	0x00,0x00,0xF8,0x00,0x04,0x01,0x04,0x01,0x0C,0x01,0x80,	// 67
	0x00,0x00,0xFC,0x01,0x04,0x01,0x04,0x01,0xD8,0x00,0x20,	// 68
	0x00,0x00,0xFC,0x01,0x24,0x01,0x24,0x01,0x24,0x01,	// 69
	0x00,0x00,0xFC,0x01,0x24,0x00,0x24,0x00,0x24,	// 70
	0x00,0x00,0xF8,0x00,0x04,0x01,0x24,0x01,0xEC,0x01,	// 71
	0x00,0x00,0xFC,0x01,0x20,0x00,0x20,0x00,0xFC,0x01,	// 72
	0x00,0x00,0x04,0x01,0xFC,0x01,0x04,0x01,0x04,0x01,	// 73
	0x00,0x00,0x80,0x01,0x04,0x01,0x04,0x01,0xFC,	// 74
	0x00,0x00,0xFC,0x01,0x20,0x00,0x78,0x00,0x84,0x00,0x00,0x01,	// 75
	0x00,0x00,0xFC,0x01,0x00,0x01,0x00,0x01,0x00,0x01,	// 76
	0x00,0x00,0xFC,0x01,0x30,0x00,0x70,0x00,0xFC,0x01,	// 77
	0x00,0x00,0xFC,0x01,0x38,0x00,0xC0,0x00,0xFC,0x01,	// 78
	0x00,0x00,0xFC,0x00,0x04,0x01,0x04,0x01,0xDC,0x00,0x20,	// 79
	0x00,0x00,0xFC,0x01,0x24,0x00,0x24,0x00,0x3C,	// 80
	0x00,0x00,0xFC,0x01,0x04,0x01,0x04,0x07,0xDC,0x04,0x20,0x04,	// 81
	0x00,0x00,0xFC,0x01,0x24,0x00,0x64,0x00,0x9C,0x01,	// 82
	0x80,0x00,0x1C,0x01,0x24,0x01,0x24,0x01,0xEC,0x01,	// 83
	0x04,0x00,0x04,0x00,0xFC,0x01,0x04,0x00,0x04,0x00,0x04,	// 84
	0x00,0x00,0xFC,0x01,0x00,0x01,0x00,0x01,0xFC,0x01,	// 85
	0x04,0x00,0x38,0x00,0xC0,0x01,0xC0,0x01,0x38,0x00,0x04,	// 86
	0x3C,0x00,0xC0,0x01,0x70,0x00,0x70,0x00,0xC0,0x01,0x3C,	// 87
	0x00,0x01,0x8C,0x00,0x70,0x00,0x70,0x00,0x8C,0x00,0x00,0x01,	// 88
	0x04,0x00,0x08,0x00,0xF0,0x01,0x30,0x00,0x08,0x00,0x04,	// 89
	0x00,0x01,0x84,0x01,0x64,0x01,0x14,0x01,0x0C,0x01,0x00,0x01,	// 90
	0x00,0x00,0x00,0x00,0xFC,0x07,0x04,0x04,0x04,0x04,	// 91
	0x00,0x00,0x0C,0x00,0x30,0x00,0x40,0x00,0x80,0x01,	// 92
	0x00,0x00,0x04,0x04,0x04,0x04,0xFC,0x07,	// 93
	0x00,0x00,0x30,0x00,0x0C,0x00,0x0C,0x00,0x30,	// 94
	0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,	// 95
	0x00,0x00,0x00,0x00,0x02,0x00,0x04,	// 96
	0x00,0x00,0xD0,0x01,0x50,0x01,0x50,0x01,0xE0,0x01,0x00,0x01,	// 97
	0x00,0x00,0xFC,0x01,0x10,0x01,0x10,0x01,0xF0,0x01,	// 98
	0x00,0x00,0xF0,0x01,0x10,0x01,0x10,0x01,0x10,0x01,	// 99
	0x00,0x00,0xF0,0x01,0x10,0x01,0x10,0x01,0xFC,0x01,	// 100
	0x00,0x00,0xF0,0x01,0x50,0x01,0x50,0x01,0x70,0x01,	// 101
	0x00,0x00,0x10,0x00,0xFC,0x01,0x14,0x00,0x14,	// 102
	0x00,0x00,0xF0,0x05,0x10,0x05,0x10,0x05,0xF0,0x07,	// 103
	0x00,0x00,0xFC,0x01,0x10,0x00,0x10,0x00,0xF0,0x01,	// 104
	0x00,0x00,0x10,0x01,0x10,0x01,0xF4,0x01,0x00,0x01,0x00,0x01,	// 105
	0x00,0x00,0x10,0x04,0x10,0x04,0xF4,0x07,	// 106
	0x00,0x00,0xFC,0x01,0x40,0x00,0xE0,0x00,0x10,0x01,	// 107
	0x00,0x00,0x04,0x01,0x04,0x01,0xFC,0x01,0x00,0x01,	// 108
	0xF0,0x01,0x10,0x00,0xD0,0x01,0x30,0x00,0xF0,0x01,	// 109
	0x00,0x00,0xF0,0x01,0x10,0x00,0x10,0x00,0xF0,0x01,	// 110
	0x00,0x00,0xF0,0x01,0x10,0x01,0x10,0x01,0xF0,0x01,	// 111
	0x00,0x00,0xF0,0x07,0x10,0x01,0x10,0x01,0xF0,0x01,	// 112
	0x00,0x00,0xF0,0x01,0x10,0x01,0x10,0x01,0xF0,0x07,	// 113
	0x00,0x00,0xF0,0x01,0x20,0x00,0x10,0x00,0x10,	// 114
	0x00,0x00,0x30,0x01,0x50,0x01,0x50,0x01,0xD0,0x01,	// 115
	0x00,0x00,0x10,0x00,0xF8,0x01,0x10,0x01,0x10,0x01,	// 116
	0x00,0x00,0xF0,0x01,0x00,0x01,0x00,0x01,0xF0,0x01,	// 117
	0x00,0x00,0x70,0x00,0x80,0x01,0x80,0x01,0x70,	// 118
	0x70,0x00,0x80,0x01,0x60,0x00,0x60,0x00,0x80,0x01,0x70,	// 119
	0x00,0x00,0x10,0x01,0xE0,0x00,0xE0,0x00,0x10,0x01,	// 120
	0x00,0x00,0x70,0x04,0x80,0x07,0x80,0x01,0x70,	// 121
	0x00,0x00,0x90,0x01,0x50,0x01,0x30,0x01,0x10,0x01,	// 122
	0x00,0x00,0x40,0x00,0xF8,0x03,0x04,0x04,0x04,0x04,	// 123
	0x00,0x00,0x00,0x00,0xFC,0x07,	// 124
	0x00,0x00,0x04,0x04,0x04,0x04,0xF8,0x03,0x40,	// 125
	0x00,0x00,0x10,0x00,0x10,0x00,0x20,0x00,0x20,	// 126
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 127
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 128
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 129
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 130
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 131
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 132
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 133
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 134
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 135
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 136
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 137
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 138
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 139
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 140
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 141
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 142
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 143
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 144
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 145
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 146
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 147
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 148
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 149
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 150
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 151
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 152
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 153
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 154
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 155
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 156
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 157
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 158
	0x00,0x00,0xE0,0x01,0x20,0x01,0xE0,0x01,	// 159
	0x00,0x00,0x00,0x00,0xC0,0x07,0x10,	// 161
	0x00,0x00,0xF8,0x00,0x88,0x00,0x8C,0x01,0x88,	// 162
	0x20,0x01,0xF8,0x01,0x24,0x01,0x24,0x01,0x0C,0x01,0x00,0x01,	// 163
	0x00,0x00,0xF0,0x00,0x90,0x00,0x90,0x00,0xF0,	// 164
	0x00,0x00,0xAC,0x00,0xF0,0x01,0xB0,0x00,0xAC,	// 165
	0x00,0x00,0x00,0x00,0xBC,0x07,	// 166
	0x00,0x00,0x6C,0x02,0x94,0x02,0x94,0x02,0xE4,0x03,	// 167
	0x00,0x00,0x00,0x00,0x04,0x00,0x04,	// 168
	0xF8,0x00,0x24,0x01,0x54,0x01,0x54,0x01,0x04,0x01,0xF8,	// 169
	0x00,0x00,0x34,0x00,0x34,0x00,0x14,0x00,0x28,	// 170
	0x00,0x00,0x60,0x00,0x90,0x00,0x60,0x00,0x90,	// 171
	0x00,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x60,	// 172
	0x00,0x00,0x00,0x00,0x40,0x00,0x40,	// 173
	0xF8,0x00,0x74,0x01,0x34,0x01,0x74,0x01,0x04,0x01,0xF8,	// 174
	0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,	// 175
	0x00,0x00,0x00,0x00,0x1C,0x00,0x1C,	// 176
	0x00,0x00,0x20,0x01,0x78,0x01,0x20,0x01,0x20,0x01,	// 177
	0x00,0x00,0x00,0x00,0x34,0x00,0x2C,	// 178
	0x00,0x00,0x00,0x00,0x24,0x00,0x2C,0x00,0x10,	// 179
	0x00,0x00,0x00,0x00,0x04,0x00,0x02,	// 180
	0x00,0x00,0xF0,0x07,0x00,0x01,0x00,0x01,0xF0,0x01,	// 181
	0x00,0x00,0x3C,0x00,0xFC,0x07,0x04,0x00,0xFC,0x07,	// 182
	0x00,0x00,0x00,0x00,0x20,0x00,0x20,	// 183
	0x00,0x00,0x00,0x06,	// 184
	0x00,0x00,0x28,0x00,0x24,0x00,0x38,0x00,0x20,	// 185
	0x00,0x00,0x18,0x00,0x24,0x00,0x24,0x00,0x18,	// 186
	0x00,0x00,0x90,0x00,0x60,0x00,0x90,0x00,0x60,	// 187
	0x08,0x00,0x3C,0x01,0xE0,0x00,0xD8,0x00,0xA4,0x00,0xC0,0x01,	// 188
	0x08,0x00,0x3C,0x01,0xC0,0x00,0x38,0x01,0xA4,0x01,0x40,0x01,	// 189
	0x24,0x00,0x2C,0x01,0xF0,0x00,0xD8,0x00,0xA4,0x00,0xC0,0x01,	// 190
	0x00,0x00,0x00,0x07,0x80,0x04,0x50,0x04,0x00,0x06,	// 191
	0x80,0x01,0x60,0x00,0x5C,0x00,0x4D,0x00,0x70,0x00,0x80,0x01,	// 192
	0x80,0x01,0x60,0x00,0x5C,0x00,0x4D,0x00,0x70,0x00,0x80,0x01,	// 193
	0x80,0x01,0x61,0x00,0x5C,0x00,0x4C,0x00,0x71,0x00,0x80,0x01,	// 194
	0x80,0x01,0x61,0x00,0x5C,0x00,0x4D,0x00,0x70,0x00,0x80,0x01,	// 195
	0x80,0x01,0x60,0x00,0x5D,0x00,0x4D,0x00,0x70,0x00,0x80,0x01,	// 196
	0x80,0x01,0x60,0x00,0x5F,0x00,0x4F,0x00,0x70,0x00,0x80,0x01,	// 197
	0x80,0x01,0x70,0x00,0x4C,0x00,0xFC,0x01,0x24,0x01,0x24,0x01,	// 198
	0x00,0x00,0xF8,0x00,0x04,0x01,0x04,0x07,0x0C,0x01,0x80,	// 199
	0x00,0x00,0xFC,0x01,0x24,0x01,0x25,0x01,0x24,0x01,	// 200
	0x00,0x00,0xFC,0x01,0x24,0x01,0x25,0x01,0x24,0x01,	// 201
	0x00,0x00,0xFD,0x01,0x24,0x01,0x24,0x01,0x25,0x01,	// 202
	0x00,0x00,0xFC,0x01,0x25,0x01,0x25,0x01,0x24,0x01,	// 203
	0x00,0x00,0x04,0x01,0xFC,0x01,0x05,0x01,0x04,0x01,	// 204
	0x00,0x00,0x04,0x01,0xFC,0x01,0x05,0x01,0x04,0x01,	// 205
	0x00,0x00,0x05,0x01,0xFC,0x01,0x04,0x01,0x05,0x01,	// 206
	0x00,0x00,0x04,0x01,0xFD,0x01,0x05,0x01,0x04,0x01,	// 207
	0x20,0x00,0xFC,0x01,0x24,0x01,0x04,0x01,0xD8,0x00,0x20,	// 208
	0x00,0x00,0xFD,0x01,0x38,0x00,0xC1,0x00,0xFC,0x01,	// 209
	0x00,0x00,0xFC,0x00,0x04,0x01,0x05,0x01,0xDC,0x00,0x20,	// 210
	0x00,0x00,0xFC,0x00,0x04,0x01,0x05,0x01,0xDC,0x00,0x20,	// 211
	0x00,0x00,0xFD,0x00,0x04,0x01,0x04,0x01,0xDD,0x00,0x20,	// 212
	0x00,0x00,0xFD,0x00,0x04,0x01,0x05,0x01,0xDC,0x00,0x20,	// 213
	0x00,0x00,0xFC,0x00,0x05,0x01,0x05,0x01,0xDC,0x00,0x20,	// 214
	0x00,0x00,0xD8,0x00,0x60,0x00,0x50,0x00,0xD8,	// 215
	0x20,0x01,0xDC,0x00,0x64,0x01,0x14,0x01,0xDC,0x00,0x24,	// 216
	0x00,0x00,0xFC,0x01,0x00,0x01,0x01,0x01,0xFC,0x01,	// 217
	0x00,0x00,0xFC,0x01,0x00,0x01,0x01,0x01,0xFC,0x01,	// 218
	0x00,0x00,0xFD,0x01,0x00,0x01,0x00,0x01,0xFD,0x01,	// 219
	0x00,0x00,0xFC,0x01,0x01,0x01,0x01,0x01,0xFC,0x01,	// 220
	0x04,0x00,0x08,0x00,0xF0,0x01,0x31,0x00,0x08,0x00,0x04,	// 221
	0x00,0x00,0xFC,0x01,0x88,0x00,0x88,0x00,0xF8,	// 222
	0x00,0x00,0xFC,0x01,0x04,0x00,0x34,0x01,0x4C,0x01,0x80,	// 223
	0x00,0x00,0xD0,0x01,0x52,0x01,0x54,0x01,0xE0,0x01,0x00,0x01,	// 224
	0x00,0x00,0xD0,0x01,0x50,0x01,0x54,0x01,0xE2,0x01,0x00,0x01,	// 225
	0x00,0x00,0xD4,0x01,0x52,0x01,0x52,0x01,0xE4,0x01,0x00,0x01,	// 226
	0x04,0x00,0xD2,0x01,0x54,0x01,0x52,0x01,0xE0,0x01,0x00,0x01,	// 227
	0x00,0x00,0xD0,0x01,0x54,0x01,0x54,0x01,0xE0,0x01,0x00,0x01,	// 228
	0x00,0x00,0xD0,0x01,0x57,0x01,0x57,0x01,0xE0,0x01,0x00,0x01,	// 229
	0xD0,0x01,0x50,0x01,0xF0,0x00,0x50,0x01,0x50,0x01,0x60,0x01,	// 230
	0x00,0x00,0xF0,0x01,0x10,0x01,0x10,0x07,0x10,0x01,	// 231
	0x00,0x00,0xF0,0x01,0x52,0x01,0x54,0x01,0x70,0x01,	// 232
	0x00,0x00,0xF0,0x01,0x50,0x01,0x54,0x01,0x72,0x01,	// 233
	0x00,0x00,0xF4,0x01,0x52,0x01,0x52,0x01,0x74,0x01,	// 234
	0x00,0x00,0xF0,0x01,0x54,0x01,0x54,0x01,0x70,0x01,	// 235
	0x00,0x00,0x10,0x01,0x12,0x01,0xF4,0x01,0x00,0x01,0x00,0x01,	// 236
	0x00,0x00,0x10,0x01,0x10,0x01,0xF4,0x01,0x02,0x01,0x00,0x01,	// 237
	0x00,0x00,0x14,0x01,0x12,0x01,0xF2,0x01,0x04,0x01,0x00,0x01,	// 238
	0x00,0x00,0x10,0x01,0x14,0x01,0xF4,0x01,0x00,0x01,0x00,0x01,	// 239
	0x00,0x00,0xE0,0x01,0x2C,0x01,0x2C,0x01,0xF4,0x01,	// 240
	0x00,0x00,0xF4,0x01,0x12,0x00,0x14,0x00,0xF2,0x01,	// 241
	0x00,0x00,0xF0,0x01,0x12,0x01,0x14,0x01,0xF0,0x01,	// 242
	0x00,0x00,0xF0,0x01,0x10,0x01,0x14,0x01,0xF2,0x01,	// 243
	0x00,0x00,0xF4,0x01,0x12,0x01,0x12,0x01,0xF4,0x01,	// 244
	0x00,0x00,0xF4,0x01,0x12,0x01,0x14,0x01,0xF2,0x01,	// 245
	0x00,0x00,0xF0,0x01,0x14,0x01,0x14,0x01,0xF0,0x01,	// 246
	0x00,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,	// 247
	0x00,0x00,0xF0,0x01,0x50,0x01,0x30,0x01,0xF0,0x01,	// 248
	0x00,0x00,0xF0,0x01,0x02,0x01,0x04,0x01,0xF0,0x01,	// 249
	0x00,0x00,0xF0,0x01,0x00,0x01,0x04,0x01,0xF2,0x01,	// 250
	0x00,0x00,0xF4,0x01,0x02,0x01,0x02,0x01,0xF4,0x01,	// 251
	0x00,0x00,0xF0,0x01,0x04,0x01,0x04,0x01,0xF0,0x01,	// 252
	0x00,0x00,0x70,0x04,0x80,0x07,0x84,0x01,0x72,	// 253
	0x00,0x00,0xFC,0x07,0x10,0x01,0x10,0x01,0xF0,0x01,	// 254
	0x00,0x00,0x70,0x04,0x84,0x07,0x84,0x01,0x70	// 255
};
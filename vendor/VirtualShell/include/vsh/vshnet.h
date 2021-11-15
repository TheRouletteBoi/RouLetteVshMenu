#ifndef __VSHNET_H__
#define __VSHNET_H__


// vshnet_0153F84A  // ?
// vshnet_015A7B72  // ?
// vshnet_01CD9CFD  // ?
// vshnet_0257D470  // ?
// vshnet_027BB79D  // ?
// vshnet_02B4A5AA  // ?
// vshnet_02F901C5  // ?
// vshnet_03139980  // sceNpMatchingGetRoomMemberList 	int sceNpMatchingGetRoomMemberList(ctx_id, uint8_t opt[0x1C], req_id, int(1))
// vshnet_036570C4  // ?
// vshnet_0381F48C  // ?
// vshnet_047D4033  // ?
// vshnet_05E19A1D  // ?
// vshnet_05FA21EB  // ?
// vshnet_076CC0C0  // ?
// vshnet_088256A7  // ?
// vshnet_09446C60  // ?
// vshnet_09C3A86A  // ?
// vshnet_0A0694B8  // ?
// vshnet_0AA16CDD  // ?
// vshnet_0ACA6932  // ?
// vshnet_0ADC0A02  // ?
// vshnet_0B9F9475  // ?
// vshnet_0BC9ADDC  // ?
// vshnet_0C4659FF  // ?
// vshnet_0C4D87B5  // ?
// vshnet_0C567160  // ?
// vshnet_0C8F6DC5  // ?
// vshnet_0CD116E4  // ?
// vshnet_0D42E780  // ?
// vshnet_0E5CEE1B  // ?
// vshnet_0E806058  // sceNpC7yTusCreateTransaction
// vshnet_0E9DFE48  // ?
// vshnet_0EF6211C  // ?
// vshnet_0EF85527  // sceNpSignalingAddExtendedHandler 	int sceNpSignalingAddExtendedHandler(ctx_id, 1)
// vshnet_0F67C877  // sceNpC7yScoreRecordGameDataRequest?
// vshnet_0FE45BD8  // ?
// vshnet_108A87FB  // ?
// vshnet_10A06011  // ?
// vshnet_10F73566  // ?
// vshnet_11823D97  // sceNpC7yLookupAvatarImageRequest?
// vshnet_118CAF26  // ?
// vshnet_122AF93C  // sceNPC7yLookupTssImageResult
// vshnet_13563C45  // ?
// vshnet_1377851E  // ?
// vshnet_13B99F47  // ?
// vshnet_13D56523  // sceNpCommerceGetDataFlagAbort 	int sceNpCommerceGetDataFlagAbort(int req_id)
// vshnet_13DAD160  // ?
// vshnet_141F1412  // ?
// vshnet_14211FB9  // sceNpMatchingDestroyCtx 	int sceNpMatchingDestroyCtx(ctx_id, 1)
// vshnet_158032C9  // sceNpSignalingDestroyCtx 	int sceNpSignalingDestroyCtx(ctx_id, 1)
// vshnet_15910AE7  // sceNpCommerceGetDataFlagState 	int sceNpCommerceGetDataFlagState(int req_id, dataflagContainer, dataflag_num)
// vshnet_161C3786  // ?
// vshnet_16B29078  // ?
// vshnet_172A2A89  // ?
// vshnet_1871ED7D  // ?
// vshnet_18C61985  // ?
// vshnet_18D8E17E  // ?
// vshnet_19390C12  // ?
// vshnet_19B8BCF3  // ?
// vshnet_19BE84DB  // ?
// vshnet_19C2687A  // ?
// vshnet_1A04A7B1  // ?
// vshnet_1A131AD0  // ?
// vshnet_1A3FCB69  // ?
// vshnet_1AAA7568  // ?
// vshnet_1B0A2B4D  // ?
// vshnet_1B985476  // ?
// vshnet_1B9A3AAE  // ?
// vshnet_1BB46A89  // ?
// vshnet_1D071824  // ?
// vshnet_1D555F5F  // sceNpUpdateClockStart
// vshnet_1FA25660  // sceNpManagerSubSignout 	int sceNpManagerSubSignout(int(0), uint8_t npId[0x24]
// vshnet_1FA7AA51  // ?
// vshnet_21F4C573  // ?
// vshnet_2275A5EC  // ?
// vshnet_22B92723  // ?
// vshnet_233BE253  // ?
// vshnet_24054920  // ?
// vshnet_24B26C3F  // sceNpMatchingLeaveRoom 	int sceNpMatchingLeaveRoom (ctx_id, uint8_t opt[0x1C], req_id, int(1))
// vshnet_250E633D  // sceNpC7yScoreRecordScoreResult? 	int sceNpC7yScoreRecordScoreResult(int transid, int *RankNumber)
// vshnet_25829BFD  // ?
// vshnet_259AABCE  // ?
// vshnet_25AB6625  // ?
// vshnet_272AC7A7  // ?
// vshnet_2737E0AE  // ?
// vshnet_28115589  // ?
// vshnet_284458D6  // ?
// vshnet_293F1645  // ?
// vshnet_29A5C939  // ?
// vshnet_2A4C99A6  // sceNpCommerceDestroyCtx 	int sceNpCommerceDestroyCtx(ctx_id)
// vshnet_2AEE464C  // ?
// vshnet_2B2E098F  // sceNpSignalingGetLocalNetInfo 	int sceNpSignalingGetLocalNetInfo(ctx_id, uint8_t netinfo[0x1C], 1)
// vshnet_2B8A5788  // ?
// vshnet_2B8B73A9  // ?
// vshnet_2BE41ECE  // ?
// vshnet_2C393B42  // sceNpManagerUnregisterCallbackExt 	int sceNpManagerUnregisterCallbackExt()
// vshnet_2DD05B38  // ?
// vshnet_2DE80ABC  // ?
// vshnet_2E730921  // ?
// vshnet_2E7F4301  // ?
// vshnet_2F9E691F  // ?
// vshnet_2FF0B98F  // ?
// vshnet_303D9027  // ?
// vshnet_3052182A  // ?
// vshnet_30671614  // ?
// vshnet_30F07C05  // ?
// vshnet_313FEF79  // ?
// vshnet_318DE631  // ?
// vshnet_319E53BD  // sceNpManagerLoadCachedInfo 	int sceNpManagerLoadCachedInfo(int userId, uint8_t cachedInfo[0xF8])
// vshnet_31A82930  // ?
// vshnet_339312C5  // ?
// vshnet_339A7368  // ?
// vshnet_34B94D5C  // ?
// vshnet_359642A6  // ?
// vshnet_35FC0BA1  // ?
// vshnet_372E972A  // sceNpC7yScoreFreeTransactionResource? 	int sceNpC7yScoreFreeTransactionResource(int transid)
// vshnet_37A88C8B  // ?
// vshnet_38AACE2B  // ?
// vshnet_3946BBB9  // ?
// vshnet_395DACC4  // ?
// vshnet_398194FB  // ?
// vshnet_39A69619  // ?
// vshnet_39C9FBD1  // ?
// vshnet_3A058640  // ?
// vshnet_3A08871C  // ?
// vshnet_3B0018CB  // ?
// vshnet_3BE51F3E  // ?
// vshnet_3BE7CCE6  // ?
// vshnet_3C6E4521  // ?
// vshnet_3CE76AF0  // ?
// vshnet_3D66F220  // ?
// vshnet_3D7D134B  // ?
// vshnet_3DB112BE  // ?
// vshnet_3E20181D  // sceNpCommerceGetProductCategoryStart 	int sceNpCommerceGetProductCategoryStart(int ctx_id, int category_id, int lang_code, int *req_id)
// vshnet_3EB784C4  // ?
// vshnet_3F004149  // ?
// vshnet_3F59F7B6  // sceNpC7yScoreAbort? 	int sceNpC7yScoreAbort (int transid)
// vshnet_3F680668  // sceNpC7yLookupUserProfileRequest?
// vshnet_3FA7B775  // ?
// vshnet_40F9732C  // ?
// vshnet_4157B2E2  // ?
// vshnet_41AE7704  // ?
// vshnet_420B6E9A  // ?
// vshnet_4216DF9F  // sceNpManagerRegisterCallbackExt 	int sceNpManagerRegisterCallbackExt(void *callback, void *arg)
// vshnet_421E7F24  // ?
// vshnet_42332FFA  // sceNpC7yScoreGetBoardInfoResult? 	int sceNpC7yScoreGetBoardInfoResult (int transid, uint8_t ScoreBoardInfo[ ])
// vshnet_42B7A484  // ?
// vshnet_42DD31CA  // ?
// vshnet_42FA659B  // ?
// vshnet_432B3CBF  // ?
// vshnet_4347DA4A  // ?
// vshnet_4479B254  // ?
// vshnet_44A206D6  // ?
// vshnet_44EB1301  // ?
// vshnet_4550C94C  // ?
// vshnet_4559999E  // ?
// vshnet_45BFBB9E  // ?
// vshnet_46917DBF  // ?
// vshnet_469FD383  // ?
// vshnet_47E64BF6  // ?
// vshnet_47F01D6F  // ?
// vshnet_481557D4  // ?
// vshnet_481AB18E  // ?
// vshnet_483C599D  // ?
// vshnet_49876046  // ?
// vshnet_49E714AF  // ?
// vshnet_4A3AF5B4  // ?
// vshnet_4ABE18A1  // ?
// vshnet_4B347A64  // ?
// vshnet_4B53C3A3  // ?
// vshnet_4B59CF0A  // ?
// vshnet_4B952C7A  // ?
// vshnet_4BA2847A  // ?
// vshnet_4BF599EA  // ?
// vshnet_4C0765CD  // ?
// vshnet_4C45916B  // ?
// vshnet_4C726FFC  // ?
// vshnet_4C9F0992  // sceNpManagerGetPsHandle 	int sceNpManagerGetPsHandle(int(0), uint8_t psHandle[0x14]
// vshnet_4D1D9FB6  // ?
// vshnet_4D5836C8  // ?
// vshnet_4DA21DEB  // ?
// vshnet_4DB2AB3F  // ?
// vshnet_4DD12D0C  // sceNpManagerGetUserIconURL 	int sceNpManagerGetUserIconURL(int(0), uint8_t icon[0x80])
// vshnet_4DE9F4D1  // ?
// vshnet_4E12A15C  // ?
// vshnet_4E276F38  // sceNpManagerGetSubjectRegion 	int sceNpManagerGetSubjectRegion(int(0), uint8_t subjectRegion[4]
// vshnet_4E2C5CF2  // ?
// vshnet_4E7C0D0C  // ?
// vshnet_4F1B4FCC  // ?
// vshnet_501A5CC3  // ?
// vshnet_5076A94B  // ?
// vshnet_508C812C  // ?
// vshnet_50953843  // ?
// vshnet_509999A1  // ?
// vshnet_50CB806E  // ?
// vshnet_50EE5602  // gets updatelist txt and compares version
// vshnet_51036B78  // ?
// vshnet_52122E7D  // ?
// vshnet_5308DB99  // ?
// vshnet_533E302B  // ?
// vshnet_534DC541  // ?
// vshnet_53573D5C  // ?
// vshnet_537748DA  // ?
// vshnet_53B3ECC1  // ?
// vshnet_55A3349F  // ?
// vshnet_55BCC2B2  // ?
// vshnet_56779FBD  // sceNpC7yScoreInit? / SceNpRankingVshInit? 	int sceNpC7yScoreInit(void *callback, uint8_t np_debug_flag)
// vshnet_572A4D1D  // sceNpSommerceSetDataFlagStart 	int sceNpSommerceSetDataFlagStart(ctx_id, licensee_id, dataflagContainer, dataflag_num, *req_id)
// vshnet_572FFDFB  // sceNpManagerGetSubHandle 	int sceNpManagerGetSubHandle(int(0), uint8_t subHandle[0x34])
// vshnet_574F3677  // ?
// vshnet_5776F638  // ?
// vshnet_57854875  // ?
// vshnet_58AB86D8  // sceNpManagerGetSubjectStatus 	int sceNpManagerGetSubjectStatus(int(0), uint8_t subjectStatus[4]
// vshnet_58AE4BB5  // ?

int32_t vshnet_59106229(const char *url);  // overrides regular update.txt url
#define vshnet_setUpdateUrl vshnet_59106229

// vshnet_59266DA8  // ?
// vshnet_594266BE  // sceNpBasicGetInitialPresence
// vshnet_59652CEB  // ?
// vshnet_59F7579C  // ?
// vshnet_5A81ADD7  // ?
// vshnet_5A99F569  // ?
// vshnet_5BCA204F  // ?
// vshnet_5BFFBD2F  // ?
// vshnet_5C0F625C  // ?
// vshnet_5C8A9129  // ?
// vshnet_5D100E0B  // ?
// vshnet_5D9CC617  // ?
// vshnet_5DF6457E  // ?
// vshnet_5E9FDA92  // ?
// vshnet_5EA49E2A  // ?
int32_t (*vshnet_5EE098BC)(int,void*,int) = 0; // used for getting klicensee struct
// vshnet_5EE81C09  // ?
// vshnet_5EF49155  // ?
// vshnet_5F2D9EF3  // ?
// vshnet_5F4B48FA  // ?
// vshnet_5F89FFD7  // ?
// vshnet_60EDA245  // ?
// vshnet_61C2F19F  // ?
// vshnet_61EE92EB  // ?
// vshnet_62C5B840  // ?
// vshnet_63044A02  // ?
// vshnet_631E5FCF  // ?
// vshnet_63468A88  // ?
// vshnet_6430B2B9  // ?
// vshnet_6473F071  // ?
// vshnet_653969A5  // ?
// vshnet_658806BD  // ?
// vshnet_664D4973  // ?
// vshnet_66A33E18  // ?
// vshnet_66EA9546  // sceNpC7yLookupInit?
// vshnet_67032742  // ?
// vshnet_67504671  // ?
// vshnet_67634163  // ?
// vshnet_6779B4FC  // ?
// vshnet_683BF712  // ?
// vshnet_68BF4BC8  // ?
// vshnet_68D671F4  // ?
// vshnet_691BFEBD  // ?
// vshnet_6938269F  // ?
// vshnet_69799C16  // ?
// vshnet_698D266D  // ?
// vshnet_69B373BF  // ?
// vshnet_69E4C2FC  // ?
// vshnet_6B2F6012  // ?
// vshnet_6B381909  // ?
// vshnet_6B38456B  // ?
// vshnet_6BB85B12  // ?
// vshnet_6CB81EB2  // ?
// vshnet_6CFFD585  // ?
// vshnet_6D85F9B8  // ?
// vshnet_6D9C1D5E  // ?
// vshnet_6DA2AC7B  // ?
// vshnet_6E2AB18B  // ?
// vshnet_6E4A0B10  // ?
// vshnet_6ED621E0  // ?
// vshnet_6EEEB110  // ?
// vshnet_7084A801  // sceNpCommerceSetDataFlagFinish 	int sceNpCommerceSetDataFlagFinish(int req_id)
// vshnet_7089FFEE  // ?
// vshnet_70A0FDE4  // ?
// vshnet_70E48AFA  // ?
// vshnet_71117EFB  // ?
// vshnet_71A1FD42  // ?
// vshnet_71DF362C  // sceNpC7yScoreEnd? 	int sceNpC7yScoreEnd()
// vshnet_7208DC08  // ?
// vshnet_723329D8  // ?
// vshnet_72F3D524  // ?
// vshnet_72F9C360  // ?

extern "C" int32_t vshnet_731E546F(const char *);  // prints Firmware version ("%02d.%02d) 	int vshnet_731E546F(out: const char*)


// vshnet_73201336  // ?
// vshnet_735770D1  // ?
// vshnet_745B67D5  // ?
// vshnet_74EB7489  // ?
// vshnet_750F7837  // ?
// vshnet_7579B55D  // ?
// vshnet_76065485  // ?
// vshnet_76A98EDD  // ?
// vshnet_76D94642  // ?
// vshnet_76F0E6DC  // ?
// vshnet_770A32A5  // ?
// vshnet_7744F6D3  // ?
// vshnet_77653F9D  // ?
// vshnet_779BD3B8  // ?
// vshnet_77F99D41  // ?
// vshnet_782EF929  // ?
// vshnet_788759C6  // sceNpManagerGetSigninTicket 	sceNpManagerGetSigninTicket(int(0), uint8_t signinTicketData[], int *signinTicketSize
// vshnet_788B5D63  // ?
// vshnet_78A824E4  // ?
// vshnet_78D7F9AD  // ?
// vshnet_78DA9B96  // ?
// vshnet_78EA69DD  // ?
// vshnet_79225AA3  // ?
// vshnet_795C3DDE  // ?
// vshnet_7982B632  // ?
// vshnet_7A9421D8  // sceNpManagerGetStatusDuration 	int sceNpManagerGetStatusDuration(int(0), uint64_t *statusDuration
// vshnet_7B55F641  // ?
// vshnet_7BF2B5F7  // ?
// vshnet_7CE3361C  // ?
// vshnet_7D8010A0  // ?
// vshnet_7EC72067  // ?
// vshnet_7EFB2A2E  // ?
// vshnet_7F5E9785  // ?
// vshnet_7FBB39B6  // ?
// vshnet_7FF866D3  // ?
// vshnet_800C911B  // ?
// vshnet_8065A1AE  // ?
// vshnet_80A88A5C  // ?
// vshnet_80D3DA2B  // ?
// vshnet_80D678BC  // ?
// vshnet_80D71CC9  // ?
// vshnet_8155D5A6  // ?
// vshnet_82392B6A  // ?
// vshnet_827E8B4A  // ?
// vshnet_82B93B60  // ?
// vshnet_8399B04D  // ?
// vshnet_8478A915  // sceNpMatchingGetRoomMemberListLocal 	int sceNpMatchingGetRoomMemberList(ctx_id, uint8_t opt[0x1C], int *size, uint8_t roomStatus[ ], int(1))
// vshnet_84FCD5A6  // ?
// vshnet_854FE623  // sceNpCommerceGetDataFlagStart 	int sceNpCommerceGetDataFlagStart(ctx_id, licensee_id, dataflag[0x10] , dataflag_num, *req_id)
// vshnet_856858C1  // ?
// vshnet_8587A3C2  // ?
// vshnet_85AA0B00  // ?
// vshnet_85E367E2  // ?
// vshnet_860CFB74  // ?
// vshnet_8622C3BC  // ?
// vshnet_8653F29F  // ?
// vshnet_868B4463  // ?
// vshnet_8698EA91  // ?
// vshnet_86C66A99  // ?
// vshnet_86C9E90F  // ?
// vshnet_87FB4A38  // ?
// vshnet_89417905  // ?
// vshnet_897D712A  // ?
// vshnet_89801F5D  // sceNpC7yTusDestroyTransaction
// vshnet_89D0D45D  // ?
// vshnet_89D3B100  // ?
// vshnet_89F650DA  // ?
// vshnet_8A3EFDDA  // ?
// vshnet_8A5C1460  // ?
// vshnet_8A74514F  // ?
// vshnet_8B5C1AE5  // ?
// vshnet_8BD9F160  // sceNpCc7yLookupCreateTransaction?
// vshnet_8C2EA0C4  // ?
// vshnet_8C760B52  // ?
// vshnet_8C967AA6  // ?
// vshnet_8C9A7A82  // ?
// vshnet_8CD3490B  // ?
// vshnet_8D1D096C  // ?
// vshnet_8DD616DC  // ?
// vshnet_8DE11580  // ?
// vshnet_8E268196  // ?
// vshnet_8E4C5479  // ?
// vshnet_8E542A87  // ?
// vshnet_8E6C5921  // ?
// vshnet_8E72CD27  // ?
// vshnet_8FD2F1CC  // ?
// vshnet_9012A265  // sceNpC7yLookupTssImageRequest
// vshnet_90384A90  // ?
// vshnet_911CBC9C  // ?
// vshnet_915A22A1  // ?
// vshnet_9165C1AE  // ?
// vshnet_91840669  // ?
// vshnet_918A1BCB  // ?
// vshnet_91FC9948  // ?
// vshnet_920DFD1A  // ?
// vshnet_924CA6E2  // ?
// vshnet_9294B9DE  // ?
// vshnet_92F476F1  // ?
// vshnet_936DF4AA  // ?
// vshnet_93DB2FC3  // ?
// vshnet_9452F4F8  // ?
// vshnet_95445594  // ?
// vshnet_9595DA7E  // ?
// vshnet_965A7E9D  // ?
// vshnet_973340C6  // ?
// vshnet_97425FF4  // ?
// vshnet_977FE1DA  // ?
// vshnet_97FAA480  // ?
// vshnet_9822DAE2  // ?
// vshnet_98340E57  // sceNpCommerceCreateCtx 	int sceNpCommerceCreateCtx(int version, uint8_t npId[0x24], void *callback, int *arg, int *ctx_id, int(1))
// vshnet_98DC7D0D  // ?
// vshnet_98EBFC9D  // ?
// vshnet_9905F8F2  // ?
// vshnet_992CA5F0  // ?
// vshnet_993581CD  // ?
// vshnet_99536505  // ?
// vshnet_995D1D2F  // sceNpSignalingGetConnectionStatus 	int sceNpSignalingGetConnectionStatus(ctx_id, conn_id, int *conn_status,int *peer_addr, uint16_t *peer_port, 1)
// vshnet_99666F31  // sceNpManagerGetEnvnamae 	int sceNpManagerGetEnvnamae(uint8_t envname[0x0F])
// vshnet_99BA9EF9  // ?
// vshnet_99DD4E02  // ?
// vshnet_9A919775  // ?
// vshnet_9AC9686E  // ?
// vshnet_9D453CAB  // ?
// vshnet_9DC56631  // ?
// vshnet_9DDB30CE  // ?
// vshnet_9E1FE092  // ?
// vshnet_9E83CC61  // ?
// vshnet_9EA2D869  // sceNpC7yLookupNpIdResult?
// vshnet_9EE83473  // ?
// vshnet_9EED8D14  // ?
// vshnet_9EF14F7C  // sceNpManagerIsPlus 	int attr_is_plus sceNpManagerIsPlus(int(0))
// vshnet_9FEF4A0B  // ?
// vshnet_A054C886  // ?
// vshnet_A077B83B  // ?
// vshnet_A08E9744  // ?
// vshnet_A12FF4C6  // ?
// vshnet_A1B292A4  // ?
// vshnet_A1C03CE6  // ?
// vshnet_A1E83573  // ?
// vshnet_A23E4DC7  // ?
// vshnet_A24C5656  // ?
// vshnet_A3000F72  // ?
// vshnet_A3B0BC4F  // ?
// vshnet_A3C53DB3  // ?
// vshnet_A43F2CD1  // ?
// vshnet_A44B614C  // ?
// vshnet_A46ABF93  // ?
// vshnet_A5E88D4E  // checks if hdd has been replaced
// vshnet_A67B323A  // ?
// vshnet_A67CE3C6  // ?
// vshnet_A6EEFF78  // ?
// vshnet_A77A90BC  // ?
// vshnet_A85A4951  // ?
// vshnet_A9FE3368  // ?
// vshnet_AACAC42B  // ?
// vshnet_AAF27E6D  // ?
// vshnet_AB2628C9  // ?
// vshnet_ABB75F66  // ?
// vshnet_ACE6D203  // ?
// vshnet_AD1DAC64  // ?
// vshnet_ADC82D95  // ?
// vshnet_AEE8CF71  // ?
// vshnet_AF57D9C9  // ?
// vshnet_AFC62605  // ?
// vshnet_AFE34072  // ?
// vshnet_B07041BE  // ?
// vshnet_B174486D  // ?
// vshnet_B1C02D66  // ?
// vshnet_B1CC0B07  // ?
// vshnet_B2882D07  // ?
// vshnet_B2EC0E06  // ?
// vshnet_B31615FF  // ?
// vshnet_B3338072  // ?
// vshnet_B38524D1  // ?
// vshnet_B3C1556E  // ?
// vshnet_B3D402A0  // ?
// vshnet_B45F6C17  // sceNpC7yLookupAbort? 	int sceNpC7yLookupAbort(transid)
// vshnet_B4F8BE6E  // ?
// vshnet_B4FD3737  // ?
// vshnet_B5996784  // ?
// vshnet_B5E257AF  // ?
// vshnet_B76CFD6A  // ?
// vshnet_B79B2FE0  // sceNpManagerGetNetworkTime 	int sceNpManagerGetNetworkTime(int(0), uint8_t casualClock[8])
// vshnet_B7F9023C  // ?
// vshnet_B835A29C  // ?
// vshnet_B98F05B8  // ?
// vshnet_BA65DE6D  // ?
// vshnet_BABC50AD  // ?
// vshnet_BB285858  // ?
// vshnet_BBADA16B  // ?
// vshnet_BD2FED0E  // ?
// vshnet_BDD6258E  // ?
// vshnet_BDEF9427  // ?
// vshnet_BE3AF96E  // ?
// vshnet_BECD4B67  // ?
// vshnet_BEF43835  // ?
// vshnet_BFD7629C  // ?
// vshnet_BFE02694  // ?
// vshnet_C00D5276  // ?
// vshnet_C097E7DD  // ?
// vshnet_C0AB392E  // ?
// vshnet_C0AEF6AB  // ?
// vshnet_C0B24CA6  // ?
// vshnet_C0C4E042  // ?
// vshnet_C10FD30A  // ?
// vshnet_C13FF75A  // ?
// vshnet_C1BC3E57  // sceNpUpdateClockAbort
// vshnet_C20DC634  // ?
// vshnet_C2CED2B7  // ?
// vshnet_C3277EF4  // ?
// vshnet_C3417866  // sceNpManagerGetTicketParam
// vshnet_C3560DB9  // ?
// vshnet_C38B06E4  // ?
// vshnet_C3C44417  // ?
// vshnet_C3C9EB24  // ?
// vshnet_C3CB8558  // ?
// vshnet_C3E1C200  // ?
// vshnet_C3F08375  // ?
// vshnet_C500119D  // ?
// vshnet_C53BF20C  // ?
// vshnet_C53DFC12  // ?
// vshnet_C560907A  // ?
// vshnet_C5945CC2  // ?
// vshnet_C611029A  // ?
// vshnet_C6BFE5B8  // ?
// vshnet_C76C2DAF  // ?
// vshnet_C7741E07  // ?
// vshnet_C84B6C8C  // ?
// vshnet_C84EAA2B  // ?
// vshnet_C880F37D  // ?
// vshnet_C8C1AF9C  // ?
// vshnet_C94EB065  // ?
// vshnet_C98BFFD8  // ?
// vshnet_C99EE313  // ?
// vshnet_CA22FF06  // ?
// vshnet_CB226149  // ?
// vshnet_CB905530  // ?
// vshnet_CB90E87F  // ?
// vshnet_CB991777  // ?
// vshnet_CB9D61C2  // ?
// vshnet_CC014646  // sceNpC7yScoreDestroyTransaction? 	int sceNpC7yScoreDestroyTransaction(int transid)
// vshnet_CC8F9206  // ?
// vshnet_CCBE2E69  // ?
// vshnet_CCC6E177  // ?
// vshnet_CD1DE92F  // ?
// vshnet_CD7DCCF1  // ?
// vshnet_CD803A70  // ?
// vshnet_CE02F174  // ?
// vshnet_CE3CCAE6  // ?
// vshnet_CE9BE1CD  // ?
// vshnet_CF725EB1  // sceNpInstallerRegetSigninTicket 	int sceNpInstallerRegetSigninTicket(0)
// vshnet_D122C015  // ?
// vshnet_D1307BEF  // ?
// vshnet_D1C98AF5  // ?
// vshnet_D208F91D  // ?
// vshnet_D2671D11  // ?
// vshnet_D28A540C  // ?
// vshnet_D297EF28  // sceNpCommerceGetProductCategoryAbort 	int sceNpCommerceGetProductCategoryAbort(int req_id)
// vshnet_D311E037  // ?
// vshnet_D311F021  // ?
// vshnet_D338736E  // ?
// vshnet_D34416D9  // ?
// vshnet_D3838A86  // ?
// vshnet_D4124A71  // ?
// vshnet_D4D3F2AB  // ?
// vshnet_D4FEADB8  // ?
// vshnet_D52B1C5F  // ?
// vshnet_D5FC3ED0  // ?
// vshnet_D61DF762  // ?
// vshnet_D77B8CBF  // ?
// vshnet_D79D5840  // sceNpC7yScoreGetGameDataResult?
// vshnet_D80B1697  // ?
// vshnet_D815DF3B  // ?
// vshnet_D8179B94  // ?
// vshnet_D910072E  // ?
// vshnet_D9CA7733  // ?
// vshnet_DA5FD769  // ?
// vshnet_DA5FF19C  // ?
// vshnet_DA8FF8B8  // ?
// vshnet_DADFAF66  // ?
// vshnet_DB49A61D  // ?
// vshnet_DB6FFC44  // ?
// vshnet_DB92AD54  // ?
// vshnet_DBF3FA04  // ?
// vshnet_DD37DEB3  // ?
// vshnet_DD508B56  // ?
// vshnet_DDF7E722  // ?
// vshnet_DE2B44CF  // ?
// vshnet_DE3ABE31  // ?
// vshnet_DEA05C5B  // ?
// vshnet_DF1FF79F  // sceNpC7yScoreCreateTransaction? 	int sceNpC7yScoreCreateTransaction(uint8_t psHandle[0x14], uint8_t ScorePassphrase[0x80])
// vshnet_DFA21880  // ?
// vshnet_E07FCB99  // ?
// vshnet_E186DD71  // ?
// vshnet_E1BF38FC  // ?
// vshnet_E2201D8B  // sceNpC7yTusEnd
// vshnet_E231CC0D  // ?
// vshnet_E2858CCB  // ?
// vshnet_E2A0CB65  // sceNpCommerceGetProductCategoryResult 	int sceNpCommerceGetProductCategoryResult(int req_id, uint8_t result_buf_size[0x10])
// vshnet_E3D2DEEE  // ?
// vshnet_E5CBDF3D  // sceNpSignalingGetConnectionInfo 	int sceNpSignalingGetConnectionInfo(ctx_id, conn_id, code, *rtt/bandwith/addr/port/packet_loss, 1)
// vshnet_E6205D77  // ?
// vshnet_E62A0E88  // ?
// vshnet_E64B4379  // ?
// vshnet_E6CB8641  // ?
// vshnet_E7AA1971  // ?
// vshnet_E84BBCAF  // sceNpCommerceGetProductCategoryFinish 	int sceNpCommerceGetProductCategoryFinish(int req_id)
// vshnet_E907E89D  // ?
// vshnet_E92C7506  // ?
// vshnet_E939E601  // ?
// vshnet_EA21EE28  // ?
// vshnet_EA3527CF  // ?
// vshnet_EA5516A5  // ?
// vshnet_EB4027D6  // ?
// vshnet_EB5F2544  // ?
// vshnet_EB9DF054  // ?
// vshnet_EBEA23A1  // sceNetHttpXmlConsoleInfoBitOpe 	int sceNetHttpXmlConsoleInfoBitOpe(0x190, xml?,1,1)
// vshnet_EC45E5A8  // ?
// vshnet_EC6FC2CC  // ?
// vshnet_EC969F67  // sceNpC7yLookupDestroyTransaction?
// vshnet_ECC6F99F  // ?
// vshnet_ECE103E9  // ?
// vshnet_ECE75E73  // ?
// vshnet_ED75819B  // ?
// vshnet_EDA4250D  // ?
// vshnet_EE530059  // ?
// vshnet_EE998600  // ?
// vshnet_EEF8AC4B  // sceNpC7yLookupAvatarImageResult?
// vshnet_EF51375F  // ?
// vshnet_EF7EF757  // ?
// vshnet_EFB67F8E  // ?
// vshnet_EFDFA6F6  // ?
// vshnet_F02E64BF  // sceNpC7yLookupEnd?
// vshnet_F0A2FF34  // ?
// vshnet_F0DB5A53  // ?
// vshnet_F2783298  // ?
// vshnet_F293BB66  // ?
// vshnet_F2D06AC2  // ?
// vshnet_F2FCA6A9  // ?
// vshnet_F31D004E  // ?
// vshnet_F36B7619  // ?
// vshnet_F3A8CEA6  // ?
// vshnet_F4F94F46  // sceNpC7yLookupUserProfileResult?
// vshnet_F511F776  // ?
// vshnet_F568E94C  // ?
// vshnet_F5847AA3  // ?
// vshnet_F5BEE8C4  // ?
// vshnet_F5FBFB50  // sceNpC7yScoreGetGameDataRequest?
// vshnet_F5FF5F31  // ?
// vshnet_F6006766  // ?
// vshnet_F6438A72  // ?
// vshnet_F6557AD3  // ?
// vshnet_F66088D8  // ?
// vshnet_F677A137  // ?
// vshnet_F7501C3F  // ?
// vshnet_F7A88701  // sceNpC7yLookupNpIdRequest?
// vshnet_F85C926D  // ?
// vshnet_F8778972  // ?
// vshnet_F87F7C01  // ?
// vshnet_F8DDFB99  // ?
// vshnet_F9884100  // sceNpC7yTusInit
// vshnet_F9CCFF2A  // ?
// vshnet_FA1A13F3  // ?
// vshnet_FA46B96A  // ?
// vshnet_FA6354BF  // ?
// vshnet_FABBDEF6  // ?
// vshnet_FACC5962  // sceNpManagerGetMyLanguages 	int sceNpManagerGetMyLanguages (int (0), uint8_t myLang[0x10]
// vshnet_FB08A795  // ?
// vshnet_FBFD0205  // ?
// vshnet_FC015E62  // sceNpC7yScoreGetBoardInfoRequest? 	int sceNpC7yScoreGetBoardInfoRequest(int transid, uint8_t SelfNpId[ ], uint8_t TitleId[0xC], int ScoreBoardId)
// vshnet_FC656EA9  // ?
// vshnet_FC663F7F  // sceNpSignalingGetPeerNetInfoResult 	int sceNpSignalingGetPeerNetInfoResult(ctx_id, req_id, uint8_t netinfo[0x1C], 1)
// vshnet_FC68F277  // ?
// vshnet_FC7303C5  // sceNpManagerGetNpId 	int sceNpManagerGetNpId(int(0), uint8_t npId[0x24]
// vshnet_FD6C8563  // ?
// vshnet_FDA460B4  // ?
// vshnet_FDB5F09F  // ?
// vshnet_FF4CD1FC  // ?
// vshnet_FF500259  // sceNpCommerceGetDataFlagFinish 	int sceNpCommerceGetDataFlagFinish(int req_id)
// vshnet_FFE3C63B  // ?


#endif // __VSHNET_H__

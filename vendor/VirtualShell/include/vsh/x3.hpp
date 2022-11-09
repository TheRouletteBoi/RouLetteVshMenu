#ifndef __X3_HPP__
#define __X3_HPP__

namespace x3
{
    CDECL_BEGIN

        // x3_003745F4	_ZN13bXCeXMLParser6ResumeEh	bXCeXMLParser::Resume(unsigned char)
    // x3_05471587	_ZNK7bXCeDoc11GetNodeTypeEP8bXCeNode	bXCeDoc::GetNodeType(bXCeNode *)const
    // x3_059D2C50	_ZNK7bXCeDoc10GetDocRootEv	bXCeDoc::GetDocRoot(void)
    // x3_0793CAA0	_ZNK7bXCeDoc11GetNextAttrEP8bXCeNode	bXCeDoc::GetNextAttr(bXCeNode *)const
    // x3_09486747  // ?
    // x3_0A06976E	sceSystemFileGetIndexInfo
    // x3_0EA628EA  // ?
    // x3_106D7436	_ZNK7bXCeDoc10GetSiblingEP8bXCeNode	bXCeDoc::GetSibling(bXCeNode *)const
    // x3_11409ED3	xRegistryGetDefaultInstance	int xRegistryGetDefaultInstance (1, &handle)
    // x3_129EE11A	_ZN7bXCeDoc11RemoveChildEP8bXCeNodeS1_	bXCeDoc::RemoveChild(bXCeNode *, bXCeNode *)
    // x3_12B480D0	xRegistryGetList
    // x3_13C32B71	bXCeMemDestroy
    // x3_16E0B7A4	_ZN7bXUtils7DestroyEv	bXUtils::Destroy(void)
    // x3_16FA740A	xCore_GetInterface	uint32_t* interface xCore_GetInterface()
    // x3_174754F0	_ZNK7bXCeDoc8GetChildEP8bXCeNode	bXCeDoc::GetChild(bXCeNode *)const
    // x3_17E56280	bXCeMemAlloc
    // x3_1A6BEE58	_ZN13bXCeXMLParser5ParseEPKcib	bXCeXMLParser::Parse(char const*, int, bool)
    // x3_1D666D7A	xRegistryDump_DBG
    // x3_2388D15D	_ZNK7bXCeDoc12GetAttrValueEP8bXCeNode	bXCeDoc::GetAttrValue(bXCeNode *)const
    // x3_28BCCEC6	xEventHandlerGetInstance
    // x3_2EE83DE4	_ZNK7bXCeDoc12GetAttributeEPK8bXCeNodePKc	bXCeDoc::GetAttribute(bXCeNode const*, char const*)const
    // x3_30B3A034  // ?
    // x3_316C9286	_ZN7bXUtils7bXToXMLEPK7bXCeDocPPcPjb	bXUtils::bXToXML(bXCeDoc const*, char **, unsigned int *, bool)
    // x3_332B4874	_Z30x3USBMass_GetAttachedDeviceIdsPPyPi	x3USBMass_GetAttachedDeviceIds(unsigned long long **, int *)
    // x3_33587DAE	_Z31x3USBMass_GetStorageInformationyP16_xUSBStorageInfo	x3USBMass_GetStorageInformation(unsigned long long, _xUSBStorageInfo *)
    // x3_33A9E1C5  // ?
    // x3_34E2588C	xAutoMounterGetInstance
    // x3_36352AD2  // ?
    // x3_37AD4EFF	_ZN7bXCeDoc7DestroyEv	bXCeDoc::Destroy(void)
    // x3_37E5E52B  // ?
    // x3_38474239	_ZNK7bXCeDoc12GetFirstAttrEP8bXCeNode	bXCeDoc::GetFirstAttr(bXCeNode *)const
    // x3_3856343C  // ?
    // x3_3BDF774D	_ZN12bXCeAttrList5ClearEv	bXCeAttrList::Clear(void)
    // x3_3C997A99	_ZN12bXCeAttrList6LengthEv	bXCeAttrList::Length(void)
    // x3_3FC70240  // ?
    // x3_4161647F	_ZN12bXCeNodeList4ItemEj	bXCeNodeList::Item(unsigned int)
    // x3_4172107C	sceSystemFileCalcSizeW
    // x3_458D68AE	_ZN7bXUtils11GetDocumentEPcPP7bXCeDoc	bXUtils::GetDocument(char *, bXCeDoc **)
    // x3_48F9FABB	_Z23x3USBMass_GetDeviceInfoyP15_xUSBDeviceInfo	x3USBMass_GetDeviceInfo(unsigned long long, _xUSBDeviceInfo *)
    // x3_4A9C874B	sceSystemFileLoadAll
    // x3_4C027D00  // ?
    // x3_4D0651A7	xRegistryGetValue
    // x3_4D31F663	_ZN12bXCeAttrList12GetAttributeEi	bXCeAttrList::GetAttribute(int)
    // x3_4DDC6151  // ?
    // x3_515ED57B	_ZN10bXCeMemMgrnwEj	bXCeMemMgr::operator new(unsigned int)
    // x3_5858821A	sys_init_x3
    // x3_5E0BDA86	_ZN10bXCeMemMgrD2Ev	bXCeMemMgr::~bXCeMemMgr()
    // x3_61295FFE	_ZN7bXCeDoc10ImportNodeEP8bXCeNodeS1_PS_S1_	bXCeDoc::ImportNode(bXCeNode *, bXCeNode *, bXCeDoc*, bXCeNode *)
    // x3_66D61138	xRegistryDestroyList
    // x3_6813FD25	_ZN13bXCeUTF8Utils14ResolveCharRefEiPPhPi	bXCeUTF8Utils::ResolveCharRef(int, unsigned char **, int *)
    // x3_6B946D30  // ?
    // x3_6D88479C	_ZN8XMWIOCTL10DisconnectEv	XMWIOCTL::Disconnect(void)
    // x3_6EE3385D  // ?
    // x3_6F0B1117	_ZN10bXCeXMLToD10InitializeEv	bXCeXMLToD::Initialize(void)
    // x3_7066DA81	xUSBMassGetInstance
    // x3_711095A5	_ZN13bXCeXMLParser11SaveContextEv	bXCeXMLParser::SaveContext(void)
    // x3_71254CDA	_ZN8XMWIOCTL13DeviceControlEjPvyS0_y	XMWIOCTL::DeviceControl(unsigned int, void *, unsigned long long, void *, unsigned long long)
    // x3_7257947C	_ZNK7bXCeDoc11GetAttrNameEP8bXCeNode	bXCeDoc::GetAttrName(bXCeNode *)const
    // x3_748BEA6B  // ?
    // x3_769CD90E	_ZN12bXCeNodeList7DestroyEv	bXCeNodeList::Destroy(void)
    // x3_7AC4128A	_ZN7bXCeDoc14CreateTextNodeEPcj	bXCeDoc::CreateTextNode(char *, unsigned int)
    // x3_7CA3EE8E	_ZNK7bXCeDoc7GetRootEv	bXCeDoc::GetRoot(void)const
    // x3_7CAB64F4	_ZN8XMWIOCTLD1Ev	XMWIOCTL::~XMWIOCTL()
    // x3_7FD1B82B	_ZN10bXCeXMLToD7DestroyEv	bXCeXMLToD::Destroy(void)
    // x3_818DCC19	xRegistryTransactionBegin
    // x3_8194A772	xRegistryGetNewInstance
    // x3_828A7BA3	_ZN7bXCeDoc10InitializeEb	bXCeDoc::Initialize(bool)
    // x3_837211A9	sceSystemFileSaveToMemW
    // x3_853ACF0E	_Z24x3USBMass_GetStorageInfoyPKcS0_P16_xUSBStorageInfo	x3USBMass_GetStorageInfo(unsigned long long, char const*, char const*, _xUSBStorageInfo *)
    // x3_869B19A4	sceSystemFileInitFormatW
    // x3_86D60EB6  // ?
    // x3_8760D5F5	_ZN12bXCeNodeList8FindItemEPh	bXCeNodeList::FindItem(unsigned char *)
    // x3_887EC484	sys_exit_x3
    // x3_8DD3F7E7	_ZNK7bXCeDoc7GetTextEP8bXCeNode	bXCeDoc::GetText(bXCeNode *)const
    // x3_8F987385	_ZN7bXCeDoc10InsertNodeEP8bXCeNodeS1_S1_	bXCeDoc::InsertNode(bXCeNode *, bXCeNode *, bXCeNode *)
    // x3_9003AE80	bXCeMemInitialize
    // x3_917D21B9  // ?
    // x3_95AC1738	_ZN13bXCeXMLParser10InitializeEv	bXCeXMLParser::Initialize(void)
    // x3_98AF0B0D  // ?
    // x3_99E00771  // ?
    // x3_9C246A91	xBDVDGetInstance
    // x3_A0BBEBEE	_ZN8XMWIOCTLC1Ev	XMWIOCTL::XMWIOCTL(void)
    // x3_A707820F	xRegistryDestroy
    // x3_AB1C71B5	_ZNK7bXCeDoc11GetNodeNameEP8bXCeNode	bXCeDoc::GetNodeName(bXCeNode *)const
    // x3_ACD37D51	sceSystemFileOverWriteToMem
    // x3_ACF69049	xRegistryDestroyInstance
    // x3_B0452730	sceSystemFileFree
    // x3_B2F21D3A	sceSystemFileLoadAll2
    // x3_B5AB27F9	_ZN7bXUtilsD1Ev	bXUtils::~bXUtils()
    // x3_B66B5308	sceSystemFileGetIndex
    // x3_B83F9AC8	_ZN13bXCeUTF8Utils13GetHexIntegerEPiPcj	bXCeUTF8Utils::GetHexInteger(int *, char *, unsigned int)
    // x3_BB1262AA	_ZN10bXCeMemMgrdlEPv	bXCeMemMgr::operator delete(void *)
    // x3_BB904C88	_ZN10bXCeParser16SetResolveEntityEb	bXCeParser::SetResolveEntity(bool)
    // x3_C610617F	_Z23x3USBMass_GetMountEntryyP19_xUSBMassMountEntry	x3USBMass_GetMountEntry(unsigned long long, _xUSBMassMountEntry *)
    // x3_C7B03EDE	_ZN13bXCeXMLParser5ResetEv	bXCeXMLParser::Reset(void)
    // x3_CB1D791D	_ZN8XMWIOCTL19StorageDriverAccessEjPvyS0_yPy	XMWIOCTL::StorageDriverAccess(unsigned int, void *, unsigned long long, void *, unsigned long long, unsigned long long *)
    // x3_CC03A4E5	_ZN12bXCeAttrList10InitializeEv	bXCeAttrList::Initialize(void)
    // x3_CD374B29	_ZN12bXCeAttrList7DestroyEv	bXCeAttrList::Destroy(void)
    // x3_D275ADBD	_Z16x3USBMass_Formatyib	x3USBMass_Format(unsigned long long, int, bool)
    // x3_D277E345	sceSystemFileGetValuePtr
    // x3_D62A98D0	_ZN13bXCeXMLParser7DestroyEv	bXCeXMLParser::Destroy(void)
    // x3_D6A5EB3F	_ZN7bXCeDoc13GetChildNodesEP8bXCeNode	bXCeDoc::GetChildNodes(bXCeNode *)
    // x3_D98B043A	_ZN13bXCeUTF8Utils14GetNextIntegerEPiPcj	bXCeUTF8Utils::GetNextInteger(int *, char *, unsigned int)
    // x3_DAE2950C	_ZN7bXCeDoc15AddElementChildEP8bXCeNodePcP12bXCeAttrListS2_j	bXCeDoc::AddElementChild(bXCeNode *, char *, bXCeAttrList *, char *, unsigned int)
    // x3_DB5BF8B0	_ZN10bXCeParser23SkipIgnorableWhiteSpaceEb	bXCeParser::SkipIgnorableWhiteSpace(bool)
    // x3_DFD0D9A7	_ZN10bXCeXMLToD5ParseEPKcib	bXCeXMLToD::Parse(char const*, int, bool)
    // x3_E2BBDCC8	_ZN8XMWIOCTL13ConnectDeviceEy	XMWIOCTL::ConnectDevice(unsigned long long)
    // x3_E4140D31	bXCeMemFree
    // x3_E49B2FB7	_ZN12bXCeAttrList12GetAttributeEPci	bXCeAttrList::GetAttribute(char *, int)
    // x3_E74BD9CC  // ?
    // x3_E7565C90	x3_lib_init
    // x3_E75FDA8D	xRegistryAddKey
    // x3_E7EF97ED  // ?
    // x3_E9E8B32F	xCore_Exit
    // x3_EB201A52	sceSystemFileAddIndexW
    // x3_EB637C94	_ZN7bXCeDoc20GetElementsByTagNameEP8bXCeNodePc	bXCeDoc::GetElementsByTagName(bXCeNode *, char *)
    // x3_EC289A5A	_ZN7bXUtils10InitializeEv	bXUtils::Initialize(void)
    // x3_EC62EB67	xRegistryTransactionEnd
    // x3_ECACA8AD	xRegistrySetValue	Example: int SetValue(handle, "/setting/categoryVersion", 0,0,0)
    // x3_EE698B61	xUSBMassDestroyInstance
    // x3_EEAEE4EF	sceSystemFileSetValueSize
    // x3_EF2DA2AB	x3_lib_exit
    // x3_EFC6EF88	_ZN10bXCeMemMgrC2Ev	bXCeMemMgr::bXCeMemMgr(void)
    // x3_F4FA6F28	_ZN7bXCeDoc7AddAttrEP8bXCeNodePcS2_i	bXCeDoc::AddAttr(bXCeNode *, char *, char *, int)
    // x3_F85DD772	_ZN7bXUtilsC1Ev	bXUtils::bXUtils(void)
    // x3_FA705F30	xRegistryDeleteKey
    // x3_FBC581BF	_ZN12bXCeAttrList12AddAttributeEPcS0_	bXCeAttrList::AddAttribute(char *, char *)

    class xBDVD
    {
    public:
        enum DiscType
        {
            NO_DISC = 0xFFF0,
            BD_GAME = 5,
            BD_MOVIE = 9
        };

    public:
        int(*_BDInitialize)();
        int(*_BDExit)();
        int(*DoUnk2)(void *);
        int(*DoUnk3)(int *);
        int(*Execute)(int, int*, int);
        int(*DoUnk5)(int, int*, int*);
        int(*DoUnk6)(int*, int*, uint64_t, uint64_t*);
        int(*DoUnk7)(int*, uint64_t, int, uint64_t *);
        int(*DoUnk8)(int*);
        int(*DoUnk9)(int*);
        int(*DoUnk10)(int*);
        int(*DoUnk11)(int);
        int(*DoUnk12)(int);
        int(*DoUnk13)(int*);
        int(*DoUnk14)(int*);
        int(*DoUnk15)(int*);
        int(*DoUnk16)();
        int(*DoUnk17)(void*); // title id, parental level
        int(*DoUnk18)();
        DiscType(*GetDiscType)();
        int(*DoUnk20)();
        int(*DoUnk21)(); // sys_mutex_unlock
        int(*DoUnk22)(); // sys_mutex_trylock
        int(*DoUnk23)();
        int(*DoUnk24)(int*);
        int(*DoUnk25)(int*);
        int(*SetModeSense)(int);
        int(*GetModeSense)(int*);
        int(*DoUnk28)(void*);
        int(*DoUnk29)();
        int(*DoUnk30)();
        int(*DoUnk31)();
        int(*DoUnk32)(int);
        int(*DoUnk33)(int*);
    };

    xBDVD* x3_9C246A91();
    static xBDVD* xBDVDGetInstance() { return x3_9C246A91(); }

    CDECL_END
}

#endif // __X3_HPP__
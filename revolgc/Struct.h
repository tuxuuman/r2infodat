typedef unsigned short int16;
typedef unsigned short uint16;

typedef unsigned int int32;
typedef unsigned int uint32;

typedef __int64 int64;
typedef unsigned __int64 uint64;

typedef char byte;
typedef unsigned char ubyte;

public struct InfoDat {
		
	struct {
		int size;
		struct {
			uint32 DT_Item;
			
			uint32 name_size;
			char DT_Item[name_size];
			
			/*
			Оружие ближнего боя  = 1,
			Щиты = 2,
			Доспехи = 3,
			Кольца = 4,
			Ожерелья = 5,
			Сапоги = 6,
			Перчатки = 7,
			Шлема = 8,
			Ремни = 9,
			Зелья, яды  = 10,
			Сунудки, сера, руны  = 11,
			Книги мага, морфа = 12,
			Книги умений 13,
			Бафы, еда = 14,
			Плащи = 17,
			Оружие дальнего бота = 18
			*/
			uint32 IType;
			
			/*
			Стакается ли придмет
			0 - нет
			1 - да
			*/
			uint32 IMaxStack;
			
			uint16 IWeight;
			
			/*
			Является ли предмет временным, тут малех странные числа для этого
			0 - для временных
			10000 - для не временных
			встречаются еще и другие значения
			*/
			int32 ITermOfValidity;
			
			uint32 desc_size;
			char IDesc[desc_size];
			
			/*
			как используется предмет
			0 - экипируется
			1 - простое использование (как еду, хилку и др.)
			4 - применяется на другой предмет (зелье идетификации. святая вода и тд)
			5 - усиляет другой предмет (точка, камень усиления тд.)
			12 - сундук
			*/
			int16 IUseType;
			
			ubyte UnknownData1[6];
			byte IStatus;
			byte UnknownVal;
			int32 IFakeID;
			
			uint32 usemsg_size;
			// текст сообщения при использовании предмета (пишется в системном чате при использовании предмета)
			char IUseMsg[usemsg_size];
			
			uint32 Unknown1TextLength;
			char Unknown1Text[Unknown1TextLength];
			
			// максимальное расстояние использования предмета (дистанция атаки для пух, дистанция применения для свиток и др.)
			uint16 IRange;
			
			/*
			Битовая маска классов персонажей которые могут использовать предмет
			-1 - все классы
			воин = 1,
			рэйн = 2,
			маг = 4,
			син = 8,
			сум = 16
			*/
			byte IUseClass;
			
			// id модельки предмета когда он лежит на земле
			uint32 IDropEffect;
			
			// уровень персонажа необходимый для использования предмета
			// > 0 - минимальный уровень
			// < 0 - максимальный уровень
			// 0 - любой лвл
			int16 IUseLevel;
			
			// Уровень предмета
			// Типа уровень мощи предмета наверное. хз
			byte ILevel;
			
			byte UnknownData2[2];
			
			// Время перезарядки предмета (кулдаун)
			int32 IUseDelay;
			
			ubyte UnknownData3[6];
			
			/*
			требуемое кол-во маны для использования предмета,
			отображается в описании предмета. хз откуда берется.
			в таблице DT_Item нету этого параметра
			*/
			int16 ManaCost;
			
			/*
			требуемое кол-во жизней для использования предмета,
			отображается в описании предмета. хз откуда берется.
			в таблице DT_Item нету этого параметра
			*/
			int16 HPCost;
			
			byte UnknownData4[4];
			
			// Является ли предмет замочным
			byte IIsIndict;
			
			// Является ли предмет премиумным
			byte IIsCharge;
			
			// Категория предмета в которой можно найти предмет в поиске торговой лавки
			byte IPShopItemType;
			int64 INationOp;
			
			// Уровень контента в котором был добавлен предмет
			byte IContentsLv;
			
			// Является ли предмет запечатываемым
			byte IIsSealable;
			
			// Требуемое кол-во рун снятия печати
			byte mSealRemovalNeedCnt;
			
			ubyte UnknownData5[4];
			
			int16 IAddLongAttackRange;
			int16 IGetItemFeedback;
			ubyte UnknownData6[2];
			
			// Максимальное кол-во слотов для рун
			byte IMaxBeadHoleCount;
		} Item[size];
	} DT_Item;

	struct{
		int size;
		struct {
			int IID;
			int SID;
		} ItemSkill[size];
	} DT_ItemSkill;

	struct{
		int size;
		struct {
			int MID;
			int name_size;
			char MName[name_size];
			int MClass;
			short MGbjType;
			short MAiType;
			int mAttackRange;
			short MCastingDelay;
			float mScale;
			uint64 mNationOp;
			ubyte IContentsLv;
			ubyte mIsShowHp;
			ubyte hz1;
			ubyte hz2;
			short hz3;
			short hz4;
			ubyte hz5;
			short mEventQuest;
			float mScale2; // странная фигня, всегда одинаковая
		} Monster[size];
	} DT_Monster;

	struct{
		int size;
		struct {
			int RID;
			int ROwnerID; // ID предмета
			int RType;
			int name_size;
			char RFileName[name_size];
			int RPosX;
			int RPosY;
		} ItemResource[size];
	} DT_ItemResource;

	struct{
		int size;
		struct {
			int RID;
			int ROwnerID;
			int RType;
			int name_size;
			char RFileName[name_size];
			int RPosX;
			int RPosY;
		} MonsterResource[size];
	} DT_MonsterResource;

	struct{
		int size;
		struct {
			short SGroupNo;
			short SIgnoreGroup;
		} SkillIgnoreCastingDelayGroup[size];
	} DT_SkillIgnoreCastingDelayGroup;

	struct{
		int size;
		struct {
			int SID;
			int name_size;
			char SName[name_size];
			short SMPPerUse;
			short SSpellNum;
			short SType;
			short SHPPerUse;
			short hz1;
			short mApplyRace;
			short mCastingDelay;
			short SChaoUse;
			int anim_size;
			char mAnimation[anim_size];
			short mCastingSpeed;
			int mSkillEffect;
			short mCAmShakeWhenHit;
			short mCriticalEffectWhenHit;
			int mCoolTime;
			short mCastingGroup;
			short mCoolTimeGroup;
			int mConsumeItem;
			short mConsumeItemCnt;
			int mConsumeItem2;
			short mConsumeItemCnt2;
			byte mIsCancel;
			byte mIsAttack;
		} Skill[size];
	} DT_Skill;

	struct{
		int size;
		struct {
			int AType;
			int name_size;
			char AName[name_size];
			int AEffect;
			short ARemovable;
			int fname_size;
			char AFileName[fname_size];
			short AIconX;
			short AIconY;
		} AbnormalType[size];
	} TP_AbnormalType;

	struct{
		int size;
		struct {
			int AID;
			ubyte ALevel;
			int AType;
			int desc_size;
			char ADesc[desc_size];
		  } Abnormal[size];
	} DT_Abnormal;

	struct{
		int size;
		struct Quest {
			int32 mQuestNo;
			ubyte mClass;
			int mLevel1;
			int mLevel2;
			int mPreQuestNo;
			ubyte mIsOverlap;
			// из mMonsterID таблицы TblQuestRefMonster для данного квеста
			int refMonster1;
			int refMonster2;
			int refMonster3;
			int refMonster4;
			int refMonster5;
			int refMonster6;
			int refMonster7;
			int refMonster8;
			int mAbandonment;
			int mDifficulty;
			int mRewardNo;
			int mScriptType;
			int mPlace; 
			float mPosX;
			float mPosY;
			float mPosZ;
			int mVisible;
			int mTextNo;
			int mParentNo;        
			int mFindNPC;
			int mCompletionNPC;
		} Quest[size];
	} TblQuest;

	struct{
	  int size;
		struct {
		  int32 TblQuestInfo;
		  int32 mType;
		  int32 mParmA;
		  int32 mParmB;      
		  int32 mParmC;
		  int32 mSeqNo; 
		} QuestInfo[size];
	} TblQuestInfo;

	struct{
		int size;
		struct {
		  int mQuestNo;
		  int32 mType;
		  int32 mID;    
		  int32 mCnt;
		  int32 mSeqNo;
		} QuestCondition[size];
	} TblQuestCondition;

	struct{
		int size;
		struct {
		  int mRewardNo;
		  uint64 mExp;
		  int32 mID;
		  int32 mCnt;
		  short mBinding;
		  short mStatus;
		  int32 mEffTime;
		  int32 mValTime;
		} QuestReward[size];
	} TblQuestReward;

	struct{
		int size;
		struct {
			int mQuestNo;
			int kLen;
			char mQuestNmKey[kLen];
		} RegionQuest[size];
	} TblRegionQuest;

	struct{
		int size;
		struct {
			int mQuestNo;
			int mParmID;
			byte mBoss;
			byte mStepCnt;
			short mStep1;
			short mStep2;
			short mStep3;
			short mTotalCnt;
		} RegionQuestCondition[size];
	} TblRegionQuestCondition;

	struct{
		int size;
		struct {
			int mSetType;
			int name_size;
			char mSetName[name_size];
		} SetItemInfo[size];
	} TP_SetItemInfo;

	struct{
		int size;
		struct {
			int mSetType;
			int IID;
		} SetItemMember[size];
	} TblSetItemMember;

	struct{
		int size;
		struct {
			int mSetType;
			int desc_size;
			char mDesc[desc_size];
		} SetItemEffectDesc[size];
	} TP_SetItemEffectDesc;

	// типы сфер ??
	struct{
		int size;
		struct {
			int IID;
			short MType;
			short MGrade;
			short MLevel;
			short MEnchant;
		} MaterialItemInfo[size];
	} TblMaterialItemInfo;

	// дроп с сундуков
	struct{
		int size;
		struct {
			// ID сундука (предмета)
			int chestId;
			// ID предмета который выпадает
			int itemId;
		} CDrop[size];
	} ChestDrop;

	struct{
		int size;
		struct {
			int x1;
			byte mStatus;
			byte mCubeType;
			float mProb;
			int mResource;
			ubyte  mKind;
		} lItemIncSysPossibleItem[size];
	} TblItemIncSysPossibleItem;

	struct{
		int size;
		struct {
			// ID рецепта
			int mRID;
			
			// RItemID0 колонка из таблицы DT_Refine (mRID = RID)
			int RItemID0;
			
			ubyte mSort;
			int mCost;
			
			// зависит от колонки RSuccess в таблице DT_Refine (mRID = RID)
			// 1 - если RSuccess = 100 (100% крафт)
			// 0 - если RSuccess < 100 (есть шанс слома)
			ubyte safely;
			
			uint64 mNationOp;
			
			// категория
			ubyte mGroup1;
			// подкатегория
			ubyte mGroup2;
			
			// кол-во создаваемых предметов
			// RIsCreateCnt колонка из таблицы DT_Refine (mRID = RID)
			short RIsCreateCnt;
		} RefineCreateInfo[size];
	} DT_RefineCreateInfo;

	// Ингридиенты для крафта.
	// Данные из таблицы DT_RefineMaterial которые есть в DT_RefineCreateInfo.
	// Сопоставляется по RID.
	struct{
		int size;
		struct {
			int RID;
			int RItemID;
			int RNum;
			ubyte ROrderNo;
		} RefineMaterial_Craft[size];
	} DT_RefineMaterial_Craft;

	// Информация о точках которыми точатся предметы.
	// Берется из таблицы DT_RefineMaterial.
	struct {
		int size;
		struct {
			int idItem;
			int idTochki;
		} toch[size];
	} DT_RefineMaterial_Zatochka;

	struct {
		int size;
		struct {
			int id;
			int nameLen;
			char name[nameLen];
			int mValue;
			int nameKeyLen;
			char nameKey[nameKeyLen];
		} AchieveList[size];
	} DT_AchieveList;

	struct {
		int size;
		struct {
			int id;
			byte grade;
			byte rarity;
		} AchieveItemCoin[size];
	} DT_AchieveItemCoin;

	struct {
		int size;
		struct {
			int id;
			byte rarity;
			byte equipType;
			byte equipPos;
			byte abilityType;
		} AchieveItemTrophy[size];
	} DT_AchieveItemTrophy;

	struct {
		int size;
		struct {
			int id;
			ubyte rank;
			int nameLen;
			char name[nameLen];
			int nameKeyLen;
			char nameKey[nameKeyLen];
		} AchieveGuildList[size];
	} DT_AchieveGuildList;

	struct {
		int size;
		struct {
			short SType;
			int nameLen;
			char STypeNameKey[nameLen];
		} Servant[size];
	} TP_Servant;

	struct {
		int size;
		struct {
			int IID;
			short SCategory;
			ubyte SEvolutionStep;
			short SType;
		} ServantType[size];
	} TblServantType;

	struct {
		int size;
		struct {
			short id;
			short x1;
			short x2;
			short x3;
			ubyte x4;
		} unknown[size];
	} Unknown29;

	struct {
		int size;
		struct {
			int IID;
			ubyte SStep;
			int STID1;
			int STID2;
			int STID3;
		} ServantSkillTree[size];
	} TblServantSkillTree;

	struct {
		int size;
		struct {
			int IID;
			int STD1;
			int STD2;
			int RID;
		} ServantEvolution[size];
	} TblServantEvolution;

	struct {
		int size;
		struct {
			int mESPID;
			int mSPID;
			short mOrderNo;
		} SkillEnhancement[size];
	} DT_SkillEnhancement;

	struct {
		int size;
		struct {
			int mESPID;
			ubyte mOrderNo;
			int mItemID;
			int mCnt;
		} SkillEnhancementMaterial[size];
	} DT_SkillEnhancementMaterial;

	struct {
		int size;
		struct {
			int mMerchantID;
			int mMaxBuyItemCnt;
			byte mMaxTrayCnt;
		} OtherMerchantInfo[size];
	} TblOtherMerchantInfo;

	struct {
		int size;
		struct {
			int mSTID;
			int name_size;
			char mName[name_size];
		} SkillTree[size];
	} TP_SkillTree;

	struct {
		int size;
		struct {
			int DT_SkillTreeNode;
			int mSTID;
			int name_size;
			char mName[name_size];
			short mMaxLevel;
			short mNodeType;
			short mIconSlotX;
			short mIconSlotY;
			short mLineN;
			short mLineE;
			short mLineS;
			short mLineW;
			short mTermOfValidity;
		} SkillTreeNode[size];
	} DT_SkillTreeNode ;

	struct {
		int size;
		struct {
			int mSTNIID;
			int mSTNID;
			int mSPID;
			short mLevel;
		} SkillTreeNodeItem[size];
	} DT_SkillTreeNodeItem;

	struct {
		int size;
		struct {
			int mSTNIID;
			int mSTNICType;
			int mParamA;
			int mParamB;
			int mParamC;
		} SkillTreeNodeItemCondition[size];
	} DT_SkillTreeNodeItemCondition;

	struct {
		int size;
		struct {
			int mSPID;
			int name_size;
			char mName[name_size];
			int mIType;
			int mIUseType;        
			short mISubType;
			short mTermOfValidity;
			int desc_size;
			char mDesc[desc_size];
			int msg_size;
			char mUseMsg[msg_size];
			short mUseRange;
			short mUseClass;
			short mUseLevel;
			int fname_size;
			char mSpriteFile[fname_size];
			int mSpriteX;
			int mSpriteY;
			short mIsDrop;
		} SkillPack[size];
	} DT_SkillPack;

	struct {
		int size;
		struct {
			int mSPID;
			int mSID;
			short mSOrderNO;
		} SkillPackSkill[size];
	} DT_SkillPackSkill;	
};
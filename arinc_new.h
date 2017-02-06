#ifndef ARINC_H
#define ARINC_H

#include <stdint.h>
#include <string>

#define END_DATA 0x00;



typedef enum
{
	OP_PENDING					= 0x0001,			// операция еще не началась  
	OP_IN_PROGRESS				= 0x0002,			// операция выполнется
	OP_COMPLETE					= 0x0003,			// операция завершена без ошибки
	OP_IN_PROGRESS_DESCRIPTION	= 0x0004,			// операция выполняется, цель предоставила допонительную информацию
	OP_DENIED					= 0x1000,			// операция не принята
	OP_NOT_SUPPORTED			= 0x1002,			// данная операция не поддерживается
	OP_ABORTED_TARGET			= 0x1003,			// операция прервана целевым программный обеспечением
	OP_ABORTED_DATA_LOADER		= 0x1004,			// операция прервана загрузчикомданных
	OP_ABORTED_OPERATOR			= 0x1005,			// операция прервана оператором
	OP_FAILED					= 0x1007			// сбой номера загрузочного раздела / сбой загрузки файла
}ArincOperationStatusCode;


typedef enum
{
	OP_IDLE,
	OP_INFO,
	OP_UPLOAD,
	OP_MDOWNLOAD,
	OP_ODOWNLOAD,
}ArincOperation;










typedef struct
{
    uint32_t    fileLenght;                 // длина файла
    uint8_t     verionProtocol[2];          // версия протокола
    uint16_t    codeStatus;                 // код статуса приема операции
    uint8_t     lenDiscriptionFieldStatus;  // длина поля описания статуса
    uint8_t     discriptionStatus[255];     // описание статуса
}file_THW_ID_POS_LCI,
 file_THW_ID_POS_LUI,
 file_THW_ID_POS_LND,
 file_THW_ID_POS_LNO;




typedef struct
{
    uint32_t    fileLenght;                 // длина файла
    uint8_t     verionProtocol[2];          // версия протокола
    uint16_t    amountUnitHardWare;         // количесвто единиц целового аппаратного обеспечения
    uint8_t     lenLetterName;              // длина буквенного имени
    uint8_t     letterName[255];            // буквеннное имя
    uint8_t     lenSerialNumber;            // длина серийного номера
    uint8_t     serialNumber[255];          // серийный номер
    uint16_t    amountNumberSection;        // количество номеров разделов   
}file_THW_ID_POS_1,                         // LCL
file_THW_ID_POS_LCL;

typedef struct header_LCL
{
	struct		header_LCL *next;
	uint8_t     _lenNumberSection;                   						// длина номера раздела
	uint8_t     _numberSection[255];                 						// номер раздела
	uint8_t     _lenCorrection;                      						// длина поправки
	uint8_t     _correction[255];                    						// поправка
	uint8_t     _lenPurposeSection;                  						// длина назначения раздела
	uint8_t     _textPurposeSection[255];            						// текст назначения раздела
}header_LCL_file;




typedef struct
{
    uint32_t    fileLenght;                 // длина файла
    uint8_t     verionProtocol[2];          // версия протокола
    uint16_t    count;                      // счетчик
    uint16_t    codeStatusInfoOperation;    // код статуса информационной операции
    uint16_t    timerException;             // таймер исключения
    uint16_t    calcTime;                   // расчетное время
    uint8_t     lenDiscriptionFieldStatus;  // длина поля описания статуса
    uint8_t     discriptionStatus[255];     // описание статуса
}file_THW_ID_POS_2,                         // LCS
file_THW_ID_POS_LCS;



typedef struct
{
    uint32_t    fileLenght;                 // длина файла
    uint8_t     verionProtocol[2];          // версия протокола
    uint16_t    amountHeaderFile;           // число файлов-заголовков
}file_THW_ID_POS_3,                         //LUR
file_THW_ID_POS_LUR ;

typedef struct header_LUR
{
	struct		header_LUR *next;
	uint8_t     _lenNameFileHeader;                  						// длина имени файла заголовка
    uint8_t     _nameFileHeader[255];                						// имя файла заголовка
    uint8_t     _lenNameNumberLoadSection;           						// длина имени номера загрузочного раздела
    uint8_t     _nameNumberLoadSection[255];         						// имя номера загрузочного раздела
}header_LUR_file;




typedef struct
{
    uint32_t    fileLenght;                 // длина файла
    uint16_t    verionProtocol;             // версия протокола
    uint16_t    codeStatusOperationLoad;    // код статуса операции загрузки
    uint8_t     lenDiscriptionStatusLoad;   // длина описания статуса загрузки
    uint8_t     discriptionStatusLoad;      // описание статуса загрузки
    uint16_t    count;                      // счетчик
    uint16_t    timerException;             // таймер исключения
    uint16_t    calcTime;                   // рассчетное время
    uint8_t     ratioListLoad[3];           // соотношение списка загрузки
    uint16_t    amountHeaderFile;           // число файлов-заголовков
}file_THW_ID_POS_4,                         // LUS
file_THW_ID_POS_LUS;

typedef struct	header_LUS
{
	struct 		header_LUS *next;
    uint8_t     _lenNameFileHeader;                 						// длина имени файла заголовка
    uint8_t     _nameFileHeader[255];               						// имя файла заголовка
    uint8_t     _lenNameNumberLoadSection;          						// длина имени номера загрузочного раздела
    uint8_t     _nameNumberLoadSection[255];        						// имя номера загрузочного раздела
    uint8_t     _ratioLoad[3];                      						// соотношение загрузки
    uint16_t    _statusLoad;                        						// статус загрузки
    uint8_t     _lenDiscriptionStatusLoad;          						// длина описания статуса загрузки
    uint8_t     _discriptionStatusLoad[255];        						// описание статуса загрузки
}header_LUS_file;






typedef struct
{
    uint32_t    fileLenght;                 // длина файла
    uint8_t     verionProtocol[2];          // версия протокола
    uint16_t    amountFile;                 // число файлов
//----------------------------------------
    uint8_t     _lenNameFile;                       // длина имени файла
//----------------------------------------
    uint8_t     nameFile[255];              // имя файла
    uint8_t     lenDataUser;                // длина данных определяемая пользователем
    uint8_t     dataUser[255];              // данные определенные пользователем

}file_THW_ID_POS_5,                         // LNR
file_THW_ID_POS_LNR;



typedef struct
{
    uint32_t    fileLenght;                     // длина файла
    uint8_t     verionProtocol[2];              // версия протокола
    uint16_t    codeStatusOperationLoad;        // код статуса операции загрузки
    uint8_t     lenFieldDiscriptionStatusLoad;  // длина поля описания статуса загрузки
    uint8_t     discriptionStatusLoad;          // описание статуса загрузки
    uint16_t    count;                          // счетчик
    uint16_t    timerException;                 // таймер исключения
    uint16_t    calcTime;                       // расчетное время
    uint8_t     ratioListLoad[3];               // соотношение списка загрузки
    uint16_t    amountFile;                     // число файлов
}file_THW_ID_POS_6,
file_THW_ID_POS_LNS;

typedef struct header_LNS
{
	struct 		header_LNS *next;
	uint8_t     _lenNameFile;                       					// длина имени файла
	uint8_t     _nameFile[255];                     					// имя файла
	uint16_t    _statusFile;                        					// статус файла
	uint8_t     _lenDiscriptionStatusFile;          					// длина описания статуса файла
	uint8_t     _discriptionStatusFile[255];        					// описанеи статуса файла
}header_LNS_file;







typedef struct
{
    uint32_t    fileLenght;                     // длина файла
    uint8_t     verionProtocol[2];              // версия протокола
    uint16_t    amountFile;                     // число файлов
}file_THW_ID_POS_7,
file_THW_ID_POS_LNL;

typedef struct	header_LNL
{
	struct 		header_LNL *next;
	uint8_t     _lenNameFile;                       					// длина имени файла
	uint8_t     _nameFile[255];                     					// имя файла
	uint8_t     _lenDiscriptionFile;                					// длина описания файла
	uint8_t     _discriptionFile[255];              					// описаине файла
}header_LNL_file;





typedef struct
{
    uint32_t    fileLenght;                     // длина файла
    uint8_t     verionProtocol[2];              // версия протокола
    uint16_t    amountFile;                     // число файлов
}file_THW_ID_POS_8,
file_THW_ID_POS_LNA;

typedef struct header_LNA
{
	struct 		header_LNA *next;
	uint8_t     _lenNameFile;                       					// длина имени файла
	uint8_t     _nameFile[255];                     					// имя файла
}header_LNA_file;




typedef enum
{
	
}code_status;



void read_LCI(file_THW_ID_POS_LCI *file_LCI);
{
	switch(code status)
	{
		case OP_PENDING:
							// выполняется
			break;
		case OP_DENIED:
							// отказано 
			break;
			
		case OP_NOT_SUPPORTED:
							// не поддерживается
			break;
		default:
			break;
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* muticast 
224.0.0.0 - 224.0.0.255       (/24)      Local Network Control Block

224.0.1.0 - 224.0.1.255       (/24)      Internetwork Control Block
*/

int find_unicast()
{
	
}



int find_boardcast()
{
	
}



int find_multicast()
{
	
}



// структура для FIND протокола
typedef struct 
{
	int 	targetIpAddress;
	
	char 	targetHWId[16];
	char	targetType[9];
	char	targetPosition[9];
	char	targetName[21];
	char	targetManufctureCode[4];
}arincTargetIdentification;





void information()
{
	
}


void abort()
{

	
}

class DataLoader
{
    public:
    DataLoader();
    ~DataLoader();


    void initDataLoader();
};



#endif // ARINC_H

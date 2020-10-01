#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <windef.h>
#include <winnt.h>
#include <bcrypt.h>
#include "tlhelp32.h"
#include "winuser.h"
#include <tchar.h>
#include <time.h>
#include <string>
#include <thread>
#include <atlstr.h>
#include <msclr\marshal_cppstd.h>
#include <clocale>

#pragma once

namespace sThreadForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для sThread
	/// </summary>
	public ref class sThread : public System::Windows::Forms::Form
	{
	public:
		sThread(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~sThread()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ ThreadsInfo;
	protected:


	private: System::Windows::Forms::Button^ Update;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CyclesDelta;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ CopyBut;
	private: System::Windows::Forms::Label^ Info;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::CheckBox^ ByName;
	private: System::Windows::Forms::TextBox^ ByPIDText;
	private: System::Windows::Forms::TextBox^ ByNameText;
	private: System::Windows::Forms::CheckBox^ ByPID;
	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


	#pragma region Windows Form Designer generated code

		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(sThread::typeid));
			this->ThreadsInfo = (gcnew System::Windows::Forms::DataGridView());
			this->TID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CyclesDelta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Update = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->CopyBut = (gcnew System::Windows::Forms::Button());
			this->Info = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->ByPID = (gcnew System::Windows::Forms::CheckBox());
			this->ByName = (gcnew System::Windows::Forms::CheckBox());
			this->ByPIDText = (gcnew System::Windows::Forms::TextBox());
			this->ByNameText = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ThreadsInfo))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ThreadsInfo
			// 
			this->ThreadsInfo->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->ThreadsInfo->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Sunken;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Unispace", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(53)));
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->ThreadsInfo->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->ThreadsInfo->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ThreadsInfo->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->TID, this->CyclesDelta });
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::WhiteSmoke;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->ThreadsInfo->DefaultCellStyle = dataGridViewCellStyle2;
			this->ThreadsInfo->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->ThreadsInfo->Location = System::Drawing::Point(12, 12);
			this->ThreadsInfo->Name = L"ThreadsInfo";
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::WhiteSmoke;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::WhiteSmoke;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->ThreadsInfo->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->ThreadsInfo->Size = System::Drawing::Size(320, 313);
			this->ThreadsInfo->TabIndex = 0;
			this->ThreadsInfo->Visible = false;
			// 
			// TID
			// 
			this->TID->HeaderText = L"TID";
			this->TID->Name = L"TID";
			this->TID->Width = 150;
			// 
			// CyclesDelta
			// 
			this->CyclesDelta->HeaderText = L"CyclesDelta";
			this->CyclesDelta->Name = L"CyclesDelta";
			this->CyclesDelta->Width = 150;
			// 
			// Update
			// 
			this->Update->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->Update->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Update->Font = (gcnew System::Drawing::Font(L"Unispace", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Update->Location = System::Drawing::Point(350, 179);
			this->Update->Name = L"Update";
			this->Update->Size = System::Drawing::Size(190, 40);
			this->Update->TabIndex = 1;
			this->Update->Text = L"Получить потоки";
			this->Update->UseVisualStyleBackColor = false;
			this->Update->Click += gcnew System::EventHandler(this, &sThread::Update_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Unispace", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label1->Location = System::Drawing::Point(348, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(198, 19);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Выберите способ поиска:";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &sThread::timer1_Tick);
			// 
			// CopyBut
			// 
			this->CopyBut->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->CopyBut->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CopyBut->Font = (gcnew System::Drawing::Font(L"Unispace", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CopyBut->Location = System::Drawing::Point(350, 236);
			this->CopyBut->Name = L"CopyBut";
			this->CopyBut->Size = System::Drawing::Size(190, 40);
			this->CopyBut->TabIndex = 10;
			this->CopyBut->Text = L"Копировать TID";
			this->CopyBut->UseVisualStyleBackColor = false;
			this->CopyBut->Click += gcnew System::EventHandler(this, &sThread::CopyBut_Click);
			// 
			// Info
			// 
			this->Info->AutoSize = true;
			this->Info->Font = (gcnew System::Drawing::Font(L"Unispace", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Info->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->Info->Location = System::Drawing::Point(340, 306);
			this->Info->Name = L"Info";
			this->Info->Size = System::Drawing::Size(138, 19);
			this->Info->TabIndex = 5;
			this->Info->Text = L"Ожидание запуска";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->ByPID);
			this->groupBox1->Controls->Add(this->ByName);
			this->groupBox1->Controls->Add(this->ByPIDText);
			this->groupBox1->Controls->Add(this->ByNameText);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->groupBox1->Location = System::Drawing::Point(350, 38);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(190, 115);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			// 
			// ByPID
			// 
			this->ByPID->AutoSize = true;
			this->ByPID->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ByPID->Font = (gcnew System::Drawing::Font(L"Unispace", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ByPID->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->ByPID->Location = System::Drawing::Point(12, 62);
			this->ByPID->Name = L"ByPID";
			this->ByPID->Size = System::Drawing::Size(70, 19);
			this->ByPID->TabIndex = 6;
			this->ByPID->Text = L"По PID";
			this->ByPID->UseVisualStyleBackColor = true;
			this->ByPID->CheckedChanged += gcnew System::EventHandler(this, &sThread::ByPID_CheckedChanged);
			// 
			// ByName
			// 
			this->ByName->AutoSize = true;
			this->ByName->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ByName->Font = (gcnew System::Drawing::Font(L"Unispace", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ByName->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->ByName->Location = System::Drawing::Point(12, 15);
			this->ByName->Name = L"ByName";
			this->ByName->Size = System::Drawing::Size(104, 19);
			this->ByName->TabIndex = 4;
			this->ByName->Text = L"По названию ";
			this->ByName->UseVisualStyleBackColor = true;
			this->ByName->CheckedChanged += gcnew System::EventHandler(this, &sThread::ByName_CheckedChanged);
			// 
			// ByPIDText
			// 
			this->ByPIDText->Enabled = false;
			this->ByPIDText->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F));
			this->ByPIDText->Location = System::Drawing::Point(11, 82);
			this->ByPIDText->Name = L"ByPIDText";
			this->ByPIDText->Size = System::Drawing::Size(167, 22);
			this->ByPIDText->TabIndex = 5;
			// 
			// ByNameText
			// 
			this->ByNameText->Enabled = false;
			this->ByNameText->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F));
			this->ByNameText->Location = System::Drawing::Point(11, 34);
			this->ByNameText->Name = L"ByNameText";
			this->ByNameText->Size = System::Drawing::Size(167, 22);
			this->ByNameText->TabIndex = 2;
			// 
			// sThread
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->ClientSize = System::Drawing::Size(557, 336);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Info);
			this->Controls->Add(this->CopyBut);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Update);
			this->Controls->Add(this->ThreadsInfo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"sThread";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Threads Explorer";
			this->Load += gcnew System::EventHandler(this, &sThread::sThread_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ThreadsInfo))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		#pragma endregion

		DWORD ThreadID;
		bool start = false, CheckStart = false;
		int i = 0, CheckChoice = 0, counter = 0;
		internal: static int ProcID = 0;
		
		//The function checks if the process is running
		//Функция проверяет запущен ли процесс
		bool IsProcessRunning(const WCHAR* processName)
		{
			HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

			PROCESSENTRY32 pe;
			pe.dwSize = sizeof(PROCESSENTRY32);
			Process32First(hSnapshot, &pe);
			while (1)
			{
			if (wcscmp(pe.szExeFile, processName) == 0) {

				sThreadForm::sThread::ProcID = pe.th32ProcessID;
				return true;
				}

				if (!Process32Next(hSnapshot, &pe)) {

				return false;
				}
			}
		}

		//Function for converting from int to string
		//Функция для преобразования из int в string
		std::string to_string(int n)
		{
			char buf[40];
			sprintf(buf, "%d", n);
			return buf;
		}

		//Function for getting information about threads
		//Функция для получения информации о потоках		
		void GetThreadsInfo(DWORD ProcessId) {

			HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

			THREADENTRY32 threadEntry;
			threadEntry.dwSize = sizeof(THREADENTRY32);
			
			Thread32First(hThreadSnapshot, &threadEntry);

			do
			{
				if (threadEntry.th32OwnerProcessID == ProcessId)
				{
					//Adding string to a table
					//Добавление строки в таблицу
					ThreadsInfo->Rows->Add();

					//Getting the ID of the current thread
					//Получение ID текущего потока
					ThreadID = threadEntry.th32ThreadID;

					//Opening the current thread
					//Открытие текущего потока
					HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, ThreadID);

					//TID output to table
					//Вывод TID в таблицу
					ThreadsInfo->Rows[i]->Cells[0]->Value = ThreadID;

					//CyclelDelta counting
					//Подсчёт CyclelDelta
					uint64_t start, end;
					int value, length;
					std::string str_val;
					String^ str_value;

					QueryThreadCycleTime(hThread, &start);
					Sleep(900);
					QueryThreadCycleTime(hThread, &end);

					value = end - start;

					if (value > 0) {

						ThreadsInfo->Rows[i]->DefaultCellStyle->ForeColor = Color::Black;
						ThreadsInfo->Rows[i]->DefaultCellStyle->BackColor = Color::Orange;
					}

					str_val = to_string(value);
					length = str_val.length();

					//Formation of numbers for comfortable viewing
					//Форматирование числа для удобного просмотра
					switch (length)
					{

					case 4:

						str_val.insert(1, std::string(" "));

						break;

					case 5:

						str_val.insert(2, std::string(" "));

						break;

					case 6:

						str_val.insert(3, std::string(" "));

						break;

					case 7:

						str_val.insert(1, std::string(" "));
						str_val.insert(5, std::string(" "));

						break;

					case 8:

						str_val.insert(2, std::string(" "));
						str_val.insert(6, std::string(" "));

						break;

					case 9:

						str_val.insert(3, std::string(" "));
						str_val.insert(7, std::string(" "));

						break;

					default:
						break;
					}

					str_value = gcnew System::String(str_val.c_str());

					//CyclelDelta output to table
					//Вывод CyclelDelta в таблицу
					ThreadsInfo->Rows[i]->Cells[1]->Value = str_value;

					i++;

				}

			} while (Thread32Next(hThreadSnapshot, &threadEntry));

			ThreadsInfo->Visible = true;

			timer1->Stop();
			Info->Text = "Потоки получены.";
		}

		private: System::Void sThread_Load(System::Object^ sender, System::EventArgs^ e) {

			ThreadsInfo->RowHeadersVisible = false;
			ByNameText->Select();
		}
		
		private: System::Void Update_Click(System::Object^ sender, System::EventArgs^ e) {

			System::String^ proc;
			CString convertProc;

			switch (CheckChoice)
			{

			case 0:

				MessageBox::Show("Выберите способ получения!",
					"Ошибка",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);

				break;

			case 1:

				proc = ByNameText->Text;
				convertProc = proc;

				if (convertProc != L"") {

					if (IsProcessRunning(convertProc)) {

						CheckStart = true;
					}
					else {

						CheckStart = false;

						MessageBox::Show("Введённый процесс неактивен.",
							"Ошибка",
							MessageBoxButtons::OK,
							MessageBoxIcon::Error);
					}
				}
				else {

					MessageBox::Show("Введите имя процесса.",
						"Ошибка",
						MessageBoxButtons::OK,
						MessageBoxIcon::Error);
				}

				break;

			case 2:

				proc = ByPIDText->Text;
				convertProc = proc;

				try {

					ProcID = _ttoi(convertProc);

					if (ProcID == 0) {

						CheckStart = false;

						MessageBox::Show("Неккоректный ввод.",
							"Ошибка",
							MessageBoxButtons::OK,
							MessageBoxIcon::Error);

						Sleep(1000);
						timer1->Start();
					}
					else {

						CheckStart = true;
					}
				}
				catch (...) {

					CheckStart = false;

					MessageBox::Show("Неккоректный ввод.",
						"Ошибка",
						MessageBoxButtons::OK,
						MessageBoxIcon::Error);
				}

				break;

			default:
				break;
			}

			if (CheckStart) {

				if (start) {

					MessageBox::Show("При повторном получении данных о потоках форма зависнет.\n" +
						"После получения всех данных таблица обновится.",
						"Предупреждение",
						MessageBoxButtons::OK,
						MessageBoxIcon::Warning);

					i = 0;

					ThreadsInfo->Rows->Clear();
					ThreadsInfo->Columns->Clear();

					ThreadsInfo->ColumnCount = 2;
					ThreadsInfo->ColumnHeadersVisible = true;

					ThreadsInfo->Columns[0]->Name = "TID";
					ThreadsInfo->Columns[0]->HeaderText = "TID";
					ThreadsInfo->Columns[0]->Width = 150;

					ThreadsInfo->Columns[1]->Name = "CyclesDelta";
					ThreadsInfo->Columns[1]->HeaderText = "CyclesDelta";
					ThreadsInfo->Columns[1]->Width = 150;
				}
				else {

					MessageBox::Show("В процессе получения данных о потоках форма зависнет.\n" +
						"После получения всех данных на форме отобразится таблица.",
						"Предупреждение",
						MessageBoxButtons::OK,
						MessageBoxIcon::Warning);
				}

				start = true;
				GetThreadsInfo(ProcID);
			}

		}

		private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

			counter++;

			switch (counter)
			{
			case 1:

				Info->Text = "Ожидание запуска";

				break;

			case 2:

				Info->Text = "Ожидание запуска.";

				break;

			case 3:

				Info->Text = "Ожидание запуска..";

				break;

			case 4:

				Info->Text = "Ожидание запуска...";

				counter = 0;

				break;


			default:
				break;
			}
		}

		private: System::Void CopyBut_Click(System::Object^ sender, System::EventArgs^ e) {

			if (start) {

				LPCSTR source;
				String^ curThread;
				std::string strThread;

				try {

					curThread = ThreadsInfo->CurrentRow->Cells[0]->Value->ToString();
					strThread = msclr::interop::marshal_as<std::string>(curThread);
					source = strThread.c_str();

					if (OpenClipboard(0))
					{
						HGLOBAL hgBuffer;
						char* chBuffer;
						EmptyClipboard();
						hgBuffer = GlobalAlloc(GMEM_DDESHARE, 20);
						chBuffer = (char*)GlobalLock(hgBuffer);
						strcpy(chBuffer, source);
						GlobalUnlock(hgBuffer);
						SetClipboardData(CF_TEXT, hgBuffer);
						CloseClipboard();
					}

					MessageBox::Show("TID выбранного потока успешно скопирован.",
						"Информация",
						MessageBoxButtons::OK,
						MessageBoxIcon::Information);
				}
				catch (...) {

					MessageBox::Show("Ошибка копирования.",
						"Ошибка",
						MessageBoxButtons::OK,
						MessageBoxIcon::Error);
				}

			}
			else {

				MessageBox::Show("Ошибка копирования. Данные о потоках не получены.\n" +
					"Для начала нажмите кнопку \"Получить потоки\".",
					"Ошибка",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
			}

		}
   
		private: System::Void ByName_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

			if (ByName->Checked) {

				CheckChoice = 1;

				ByPID->Checked = false;

				ByPIDText->Enabled = false;
				ByNameText->Enabled = true;
			}
			else {

				CheckChoice = 0;
			}
		}

		private: System::Void ByPID_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

			if (ByPID->Checked) {

				CheckChoice = 2;

				ByName->Checked = false;

				ByNameText->Enabled = false;
				ByPIDText->Enabled = true;
			}
			else {

				CheckChoice = 0;
			}
		}

	};

}
#pragma once

#include <curl/curl.h>
#include <string>
#include <cstring>
#include <json/json.h>
#include <msclr\marshal.h>



namespace CLRNET {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ SummaryPanel;


	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ tempToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ windToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ precipitationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ visibilityToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ summaryToolStripMenuItem;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ lblSummaryHeading;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ label22;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;

	
//WRITE CALLBACK
	public: ref class Device {
	public:
		static std::size_t callback(const char* in, std::size_t size, std::size_t num, std::string* out) {
			const std::size_t totalBytes(size * num);
			out->append(in, totalBytes);
			return totalBytes;
		}
	};

	public:
		delegate size_t WriteCallbackDelegate(void* contents, size_t size, size_t nmemb, void* userp);

		static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
			if (userp == nullptr) {
				// Handle the case where userp is a null pointer
				return 0;
			}

			std::string* out = static_cast<std::string*>(userp);
			return Device::callback(static_cast<const char*>(contents), size, nmemb, out);
		}

// Perform an HTTP GET request given a URL.
	public: CURL* PerformHttpGet(const std::string& url) {

		CURL* curl = curl_easy_init();
		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

			// Response information.
			WriteCallbackDelegate^ writeCallbackDelegate = gcnew WriteCallbackDelegate(&WriteCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallbackDelegate);

			// Perform the HTTP GET request.
			CURLcode res = curl_easy_perform(curl);
			if (res != CURLE_OK) {
				label1->Text = "Failed to perform HTTP GET request: ";
			}

			// Clean up.
			curl_easy_cleanup(curl);
		}
		else {
			label1->Text = "Failed to initialize libcurl.";
		}

		return curl;
	}


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SummaryPanel = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lblSummaryHeading = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->summaryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tempToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->windToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->precipitationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->visibilityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SummaryPanel->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(677, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(718, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Bottom;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 334);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(997, 239);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(529, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(443, 5);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(931, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"label3";
			// 
			// SummaryPanel
			// 
			this->SummaryPanel->Controls->Add(this->panel1);
			this->SummaryPanel->Controls->Add(this->chart1);
			this->SummaryPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SummaryPanel->Location = System::Drawing::Point(0, 24);
			this->SummaryPanel->Name = L"SummaryPanel";
			this->SummaryPanel->Size = System::Drawing::Size(997, 573);
			this->SummaryPanel->TabIndex = 7;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel7);
			this->panel1->Controls->Add(this->panel6);
			this->panel1->Controls->Add(this->panel5);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->lblSummaryHeading);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(997, 334);
			this->panel1->TabIndex = 3;
			// 
			// panel7
			// 
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel7->Controls->Add(this->label22);
			this->panel7->Controls->Add(this->label21);
			this->panel7->Location = System::Drawing::Point(21, 43);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(372, 144);
			this->panel7->TabIndex = 7;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->Location = System::Drawing::Point(125, 17);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(83, 20);
			this->label22->TabIndex = 4;
			this->label22->Text = L"Date Here";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(87, 84);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(94, 16);
			this->label21->TabIndex = 3;
			this->label21->Text = L"Weather Code";
			// 
			// panel6
			// 
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->Controls->Add(this->label20);
			this->panel6->Controls->Add(this->label19);
			this->panel6->Controls->Add(this->label18);
			this->panel6->Location = System::Drawing::Point(21, 193);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(372, 135);
			this->panel6->TabIndex = 6;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(291, 64);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(32, 16);
			this->label20->TabIndex = 2;
			this->label20->Text = L"Max";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(33, 64);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(28, 16);
			this->label19->TabIndex = 1;
			this->label19->Text = L"Min";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(125, 15);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(100, 20);
			this->label18->TabIndex = 0;
			this->label18->Text = L"Temperature";
			// 
			// panel5
			// 
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel5->Controls->Add(this->label17);
			this->panel5->Controls->Add(this->label16);
			this->panel5->Controls->Add(this->label15);
			this->panel5->Location = System::Drawing::Point(400, 193);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(231, 135);
			this->panel5->TabIndex = 5;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(16, 101);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(91, 16);
			this->label17->TabIndex = 2;
			this->label17->Text = L"Clear sky max";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(16, 58);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(32, 16);
			this->label16->TabIndex = 1;
			this->label16->Text = L"Max";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(74, 17);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(75, 20);
			this->label15->TabIndex = 0;
			this->label15->Text = L"UV Index";
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->label14);
			this->panel4->Controls->Add(this->label13);
			this->panel4->Controls->Add(this->label12);
			this->panel4->Location = System::Drawing::Point(400, 43);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(229, 144);
			this->panel4->TabIndex = 4;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(7, 97);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(71, 16);
			this->label14->TabIndex = 2;
			this->label14->Text = L"Probability";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(7, 61);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(59, 16);
			this->label13->TabIndex = 1;
			this->label13->Text = L"Average";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline));
			this->label12->Location = System::Drawing::Point(52, 17);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(96, 20);
			this->label12->TabIndex = 0;
			this->label12->Text = L"Precipitation";
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->label10);
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Controls->Add(this->label7);
			this->panel3->Location = System::Drawing::Point(635, 193);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(347, 135);
			this->panel3->TabIndex = 3;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(183, 81);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(60, 16);
			this->label10->TabIndex = 3;
			this->label10->Text = L"Direction";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(22, 94);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(41, 16);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Gusts";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(22, 66);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(48, 16);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Speed";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(146, 19);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(45, 20);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Wind";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Location = System::Drawing::Point(635, 43);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(347, 144);
			this->panel2->TabIndex = 2;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(147, 56);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(57, 16);
			this->label11->TabIndex = 4;
			this->label11->Text = L"Duration";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(282, 56);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 16);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Sunset";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(11, 56);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(52, 16);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Sunrise";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(112, 17);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(149, 20);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Sunrise and Sunset";
			// 
			// lblSummaryHeading
			// 
			this->lblSummaryHeading->AutoSize = true;
			this->lblSummaryHeading->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblSummaryHeading->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblSummaryHeading->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSummaryHeading->Location = System::Drawing::Point(0, 0);
			this->lblSummaryHeading->Name = L"lblSummaryHeading";
			this->lblSummaryHeading->Size = System::Drawing::Size(169, 26);
			this->lblSummaryHeading->TabIndex = 0;
			this->lblSummaryHeading->Text = L"Today\'s Weather";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->summaryToolStripMenuItem,
					this->tempToolStripMenuItem, this->windToolStripMenuItem, this->precipitationToolStripMenuItem, this->visibilityToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(997, 24);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// summaryToolStripMenuItem
			// 
			this->summaryToolStripMenuItem->Name = L"summaryToolStripMenuItem";
			this->summaryToolStripMenuItem->Size = System::Drawing::Size(70, 20);
			this->summaryToolStripMenuItem->Text = L"Summary";
			this->summaryToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::summaryToolStripMenuItem_Click);
			// 
			// tempToolStripMenuItem
			// 
			this->tempToolStripMenuItem->Name = L"tempToolStripMenuItem";
			this->tempToolStripMenuItem->Size = System::Drawing::Size(85, 20);
			this->tempToolStripMenuItem->Text = L"Temperature";
			this->tempToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tempToolStripMenuItem_Click);
			// 
			// windToolStripMenuItem
			// 
			this->windToolStripMenuItem->Name = L"windToolStripMenuItem";
			this->windToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->windToolStripMenuItem->Text = L"Wind";
			this->windToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::windToolStripMenuItem_Click);
			// 
			// precipitationToolStripMenuItem
			// 
			this->precipitationToolStripMenuItem->Name = L"precipitationToolStripMenuItem";
			this->precipitationToolStripMenuItem->Size = System::Drawing::Size(86, 20);
			this->precipitationToolStripMenuItem->Text = L"Precipitation";
			// 
			// visibilityToolStripMenuItem
			// 
			this->visibilityToolStripMenuItem->Name = L"visibilityToolStripMenuItem";
			this->visibilityToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->visibilityToolStripMenuItem->Text = L"Visibility";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(997, 597);
			this->Controls->Add(this->SummaryPanel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(1013, 636);
			this->MinimumSize = System::Drawing::Size(1013, 636);
			this->Name = L"MyForm";
			this->Text = L"Luke\'s Weather";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->SummaryPanel->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


		const std::string urlWeather("https://api.open-meteo.com/v1/forecast?latitude=-26.520453&longitude=29.193603&minutely_15=temperature_2m");
		CURL* curlWeather = curl_easy_init();
		// Set remote URL.
		curl_easy_setopt(curlWeather, CURLOPT_URL, urlWeather.c_str());
		// Don't bother trying IPv6, which would increase DNS resolution time.
		curl_easy_setopt(curlWeather, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
		// Don't wait forever, time out after 10 seconds.
		curl_easy_setopt(curlWeather, CURLOPT_TIMEOUT, 10);
		// Follow HTTP redirects if necessary.
		curl_easy_setopt(curlWeather, CURLOPT_FOLLOWLOCATION, 1L);
		// Response information.
		long httpCode(0);
		std::unique_ptr<std::string> httpData(new std::string());
		// Hook up data handling function.
		WriteCallbackDelegate^ writeCallbackDelegate = gcnew WriteCallbackDelegate(&WriteCallback);
		curl_easy_setopt(curlWeather, CURLOPT_WRITEFUNCTION, writeCallbackDelegate);
		// Hook up data container (will be passed as the last parameter to the
		// callback handling function).  Can be any pointer type, since it will
		// internally be passed as a void pointer.
		curl_easy_setopt(curlWeather, CURLOPT_WRITEDATA, httpData.get());
		// Run our HTTP GET command, capture the HTTP response code, and clean up.
		curl_easy_perform(curlWeather);
		curl_easy_getinfo(curlWeather, CURLINFO_RESPONSE_CODE, &httpCode);
		curl_easy_cleanup(curlWeather);

		//CURL* Data = PerformHttpGet("https://api.open-meteo.com/v1/forecast?latitude=-26.520453&longitude=29.193603&hourly=temperature_2m&start_date=2023-12-13&end_date=2023-12-14");
		/*std::unique_ptr<std::string> httpData(new std::string());
		long httpCode(0);

		curl_easy_getinfo(Data, CURLINFO_RESPONSE_CODE, &httpCode);
		curl_easy_setopt(Data, CURLOPT_WRITEDATA, httpData.get());*/


		if (httpCode == 200)
		{

			// Assuming you have a DateTimePicker control named dateTimePicker1 to select the date
			
			Json::Reader jsonReader;
			Json::Value jsonData;
			// Parse JSON response
			if (jsonReader.parse(*httpData, jsonData)) {
				auto hourlyData = jsonData["minutely_15"];
				auto timeData = hourlyData["time"];
				auto temperatureData = hourlyData["temperature_2m"];

				// Assuming 'chart1' is a System::Windows::Forms::DataVisualization::Charting::Chart
				chart1->Series->Clear(); // Clear existing data

				// Add a series for temperature data
				System::Windows::Forms::DataVisualization::Charting::Series^ temperatureSeries = gcnew System::Windows::Forms::DataVisualization::Charting::Series("Temperature");
				temperatureSeries->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;

				// Get the date of the first data point
				System::DateTime^ firstDate = System::DateTime::Parse(gcnew System::String(timeData[0].asCString()));
				firstDate = firstDate->Date;  // Extract the date component

				// Iterate through the data and add points for each 15 minutes on the first day
				for (int i = 0; i < timeData.size(); ++i) {
					// Extract time and temperature for each data point
					System::DateTime^ dateTime = System::DateTime::Parse(gcnew System::String(timeData[i].asCString()));
					double temperature = temperatureData[i].asDouble();
					double time = dateTime->TimeOfDay.TotalHours;

					// Check if the date is the same as the first day
					if (dateTime->Year == firstDate->Year &&
						dateTime->Month == firstDate->Month &&
						dateTime->Day == firstDate->Day && time>=0.0) {
						// Add the data point to the series
						temperatureSeries->Points->AddXY(time, temperature);
					}
				}

				// Add the temperature series to the chart
				chart1->Series->Add(temperatureSeries);

				// Customize the chart appearance if needed
				chart1->ChartAreas[0]->AxisX->Title = "Time";
				chart1->ChartAreas[0]->AxisY->Title = "Temperature (°C)";
				chart1->Legends->Clear(); // Remove legends if not needed
			}

		}

		

	}
	private: System::Void windToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SummaryPanel->Visible = false;
	}
	private: System::Void tempToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SummaryPanel->Visible = false;
	}
	private: System::Void summaryToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SummaryPanel->Visible = true;
	}
};
}

#pragma once

#include <curl/curl.h>
#include <string>
#include <cstring>
#include <json/json.h>
//#include <msclr\marshal.h>
#include <map>
#include <Windows.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include <wininet.h>
#pragma comment(lib,"Wininet.lib")



namespace CLRNET {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

//Global variables
	struct Globals {
		std::string city;
		std::string latitude;
		std::string longitude;
	};

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public: Globals* global;
	public:
	

		MyForm(void)
		{
			global = new Globals();
			global->city = "Secunda";
			global->latitude = "-26.520453";
			global->longitude = "29.193603";
			// Set up the timer
			updateTimer = gcnew System::Windows::Forms::Timer();
			updateTimer->Interval = 1000; // Set the interval to 1000 milliseconds (1 second)
			updateTimer->Tick += gcnew System::EventHandler(this, &MyForm::UpdateTimer_Tick);
			updateTimer->Start();
			// Set up the BackgroundWorker
			/*backgroundWorker = gcnew System::ComponentModel::BackgroundWorker();
			backgroundWorker->WorkerReportsProgress = false;
			backgroundWorker->WorkerSupportsCancellation = false;
			backgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::BackgroundWorker_DoWork);*/
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
			/*if (global!=nullptr)
				delete global;*/
		}	





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
	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label37;
	private: System::Windows::Forms::Label^ label36;
	private: System::Windows::Forms::Label^ label35;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;



	private:   System::Windows::Forms::Timer^ updateTimer;
	private:   System::ComponentModel::BackgroundWorker^ backgroundWorker;

	
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
	//public: CURL* PerformHttpGet(const std::string& url) {

	//	CURL* curl = curl_easy_init();
	//	if (curl) {
	//		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

	//		// Response information.
	//		WriteCallbackDelegate^ writeCallbackDelegate = gcnew WriteCallbackDelegate(&WriteCallback);
	//		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallbackDelegate);

	//		// Perform the HTTP GET request.
	//		CURLcode res = curl_easy_perform(curl);
	//		if (res != CURLE_OK) {
	//			label1->Text = "Failed to perform HTTP GET request: ";
	//		}

	//		// Clean up.
	//		curl_easy_cleanup(curl);
	//	}
	//	else {
	//		label1->Text = "Failed to initialize libcurl.";
	//	}

	//	return curl;
	//}
// BackgroundWorker_DoWork event handler
	private: System::Void BackgroundWorker_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		//// Your network-related tasks (e.g., checking internet connectivity) go here
		//// You may need to implement the Connected() function and adjust the sleep duration accordingly
		//while (true) {
		//	if (Connected()) {
		//		// Connected to the internet, perform your tasks
		//		updateSummaryPage();
		//		label36->Visible = false;
		//		SummaryPanel->Visible = true;
		//		textBox2->Visible = true;
		//		label2->Visible = true;
		//		label3->Visible = true;
		//		label35->Visible = true;
		//		label37->Text = GetCurrentTime();
		//		// For testing, simulate some network-related task
		//		Sleep(1000);
		//	}
		//	else {
		//		// Not connected to the internet, handle accordingly
		//		label36->Visible = true;
		//		SummaryPanel->Visible = false;
		//		textBox2->Visible = false;
		//		label2->Visible = false;
		//		label3->Visible = false;
		//		label35->Visible = false;

		//		// For testing, simulate checking connectivity every second
		//		Sleep(1000);
		//	}
		//}
	}
// Checks Network connection
	public: bool Connected() {
		return InternetCheckConnectionA("http://www.google.com", FLAG_ICC_FORCE_CONNECTION, 0);
	}

// Timer tick event handler
	private: System::Void UpdateTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		// Update the displayed time
		//if (!backgroundWorker->IsBusy) {
		//	// Start the BackgroundWorker if it's not already busy
		//	backgroundWorker->RunWorkerAsync();
		//}
		// Update the displayed time and UI by eitehr using this way or using a background worker
		if (!Connected()) {
			label36->Visible = true;
			SummaryPanel->Visible = false;
			textBox2->Visible = false;
			label2->Visible = false;
			label3->Visible = false;
			label35->Visible = false;
		}
		else {
			if (label36->Visible) {
				updateSummaryPage();
			}
			label36->Visible = false;
			SummaryPanel->Visible = true;
			textBox2->Visible = true;
			label2->Visible = true;
			label3->Visible = true;
			label35->Visible = true;
			label37->Text = GetCurrentTime();
		}

	}
// Gets current time
	public: System::String^ GetCurrentTime() {
		auto now = std::chrono::system_clock::now();
		auto currentTime = std::chrono::system_clock::to_time_t(now);
		tm localTime;
		localtime_s(&localTime, &currentTime);

		// Format the time as "HH:mm"
		char timeBuffer[6];
		strftime(timeBuffer, sizeof(timeBuffer), "%H:%M", &localTime);

		// Convert the char array to System::String^
		System::String^ currentTimeStr = gcnew System::String(timeBuffer);

		return currentTimeStr;
	}
// Converts from string to String^ and formats numbers to 1 decimal place
	public: System::String^ ConvertString(const std::string& str) {
		try {
			// Try to convert the string to a double
			double value = std::stod(str);

			// Format the double to one decimal place
			char buffer[32];
			std::snprintf(buffer, sizeof(buffer), "%.1f", value);

			// Convert the formatted string to a System::String^
			return gcnew System::String(buffer);
		}
		catch (const std::invalid_argument&) {
			// The string could not be converted to a double, so just convert it to a System::String^
			return gcnew System::String(str.c_str());
		}
	}
// Only converts from string to String^
	public: System::String^ ConvertStringNoFormat(const std::string& str) {
		// Convert the string to a System::String^
		return gcnew System::String(str.c_str());
	}
//Converts from String^ to string
	public: std::string ConvertString(System::String^ clrString) {
		std::string stdString;

		// Convert System::String^ to const char*
		IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(clrString);
		const char* cString = static_cast<const char*>(ptr.ToPointer());

		// Convert const char* to std::string
		stdString = cString;

		// Free the memory
		System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);

		return stdString;
	}

//Extracts Time from DateTime JSON
	public: System::String^ GetTimeFromTimestamp(const std::string& timestamp) {
		// Extract the last 5 characters from the timestamp
		std::string timeStr = timestamp.substr(timestamp.size() - 5);

		// Convert the std::string to a System::String^
		System::String^ time = gcnew System::String(timeStr.c_str());

		return time;
	}
//Seconds to Hours
	public: System::String^ ConvertSecondsToHours(const std::string& secondsStr) {
		// Convert the std::string to an integer
		int seconds = std::stoi(secondsStr);

		// Convert seconds to hours
		double hours = static_cast<double>(seconds) / 3600;

		// Format the double to two decimal places
		char buffer[32];
		std::snprintf(buffer, sizeof(buffer), "%.2f", hours);

		// Convert the formatted string to a System::String^
		System::String^ hoursStr = gcnew System::String(buffer);

		return hoursStr;
	}
//Decyphers Weather code WMO
	public: System::String^ GetWeatherDescription(const std::string& code) {
		// Map of weather codes to descriptions
		std::map<std::string, std::string> weatherCodes = {
			{"0", "Clear sky"},
			{"1", "Mainly clear"},
			{"2", "Partly cloudy"},
			{"3", "Overcast"},
			{"45", "Fog"},
			{"48", "Depositing rime fog"},
			{"51", "Light drizzle"},
			{"53", "Moderate drizzle"},
			{"55", "Dense drizzle"},
			{"56", "Light freezing drizzle"},
			{"57", "Dense freezing drizzle"},
			{"61", "Slight rain"},
			{"63", "Moderate rain"},
			{"65", "Heavy rain"},
			{"66", "Light freezing rain"},
			{"67", "Heavy freezing rain"},
			{"71", "Slight snow fall"},
			{"73", "Moderate snow fall"},
			{"75", "Heavy snow fall"},
			{"77", "Snow grains"},
			{"80", "Slight rain showers"},
			{"81", "Moderate rain showers"},
			{"82", "Violent rain showers"},
			{"85", "Slight snow showers"},
			{"86", "Heavy snow showers"},
			{"95", "Slight or moderate thunderstorm"},
			{"96", "Thunderstorm with slight hail"},
			{"99", "Thunderstorm with heavy hail"}
		};

		// Find the description for the given code
		auto it = weatherCodes.find(code);
		if (it != weatherCodes.end()) {
			// Convert the std::string to a System::String^
			return gcnew System::String(it->second.c_str());
		}
		else {
			// Code not found
			return nullptr;
		}
	}
//Gets wind direction from degrees
	public: System::String^ GetWindDirection(const std::string& degreesStr) {
		// Convert the std::string to an integer
		int degrees = std::stoi(degreesStr);

		// Map of degrees to directions
		std::map<int, std::string> directions = {
			{0, "N"},
			{1, "NNE"},
			{2, "NE"},
			{3, "ENE"},
			{4, "E"},
			{5, "ESE"},
			{6, "SE"},
			{7, "SSE"},
			{8, "S"},
			{9, "SSW"},
			{10, "SW"},
			{11, "WSW"},
			{12, "W"},
			{13, "WNW"},
			{14, "NW"},
			{15, "NNW"}
		};

		// Find the direction for the given degrees
		auto it = directions.find(degrees / 22.5);
		if (it != directions.end()) {
			// Convert the std::string to a System::String^
			return gcnew System::String(it->second.c_str());
		}
		else {
			// Direction not found
			return nullptr;
		}
	}
// URL Encodes a string
	public: std::string url_encode(const std::string& decoded)
	{
		 const auto encoded_value = curl_easy_escape(nullptr, decoded.c_str(), static_cast<int>(decoded.length()));
		 std::string result(encoded_value);
		 curl_free(encoded_value);
		 return result;
	}
//URl decodes a string
	public: std::string url_decode(const std::string& encoded)
	{
		 int output_length;
		 const auto decoded_value = curl_easy_unescape(nullptr, encoded.c_str(), static_cast<int>(encoded.length()), &output_length);
		 std::string result(decoded_value, output_length);
		 curl_free(decoded_value);
		 return result;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->SummaryPanel = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
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
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
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
			this->label1->Location = System::Drawing::Point(925, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::Transparent;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Bottom;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 334);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::EarthTones;
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(997, 239);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
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
			this->panel1->Controls->Add(this->label22);
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
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label22->Location = System::Drawing::Point(175, 6);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(73, 17);
			this->label22->TabIndex = 4;
			this->label22->Text = L"Date Here";
			// 
			// panel7
			// 
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel7->Controls->Add(this->label37);
			this->panel7->Controls->Add(this->label21);
			this->panel7->Location = System::Drawing::Point(21, 43);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(372, 144);
			this->panel7->TabIndex = 7;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(160, 100);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(67, 20);
			this->label37->TabIndex = 4;
			this->label37->Text = L"label37";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(135, 32);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(124, 20);
			this->label21->TabIndex = 3;
			this->label21->Text = L"Weather Code";
			// 
			// panel6
			// 
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->Controls->Add(this->label34);
			this->panel6->Controls->Add(this->label33);
			this->panel6->Controls->Add(this->label20);
			this->panel6->Controls->Add(this->label19);
			this->panel6->Controls->Add(this->label18);
			this->panel6->Location = System::Drawing::Point(21, 193);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(372, 135);
			this->panel6->TabIndex = 6;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label34->Location = System::Drawing::Point(23, 101);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(51, 16);
			this->label34->TabIndex = 5;
			this->label34->Text = L"label34";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label33->Location = System::Drawing::Point(251, 101);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(51, 16);
			this->label33->TabIndex = 4;
			this->label33->Text = L"label33";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(260, 64);
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
			this->panel5->Controls->Add(this->label32);
			this->panel5->Controls->Add(this->label31);
			this->panel5->Controls->Add(this->label17);
			this->panel5->Controls->Add(this->label16);
			this->panel5->Controls->Add(this->label15);
			this->panel5->Location = System::Drawing::Point(400, 193);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(231, 135);
			this->panel5->TabIndex = 5;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label32->Location = System::Drawing::Point(138, 101);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(51, 16);
			this->label32->TabIndex = 5;
			this->label32->Text = L"label32";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->Location = System::Drawing::Point(138, 58);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(51, 16);
			this->label31->TabIndex = 4;
			this->label31->Text = L"label31";
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
			this->panel4->Controls->Add(this->label24);
			this->panel4->Controls->Add(this->label23);
			this->panel4->Controls->Add(this->label14);
			this->panel4->Controls->Add(this->label13);
			this->panel4->Controls->Add(this->label12);
			this->panel4->Location = System::Drawing::Point(400, 43);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(229, 144);
			this->panel4->TabIndex = 4;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(138, 97);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(51, 16);
			this->label24->TabIndex = 4;
			this->label24->Text = L"label24";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(138, 61);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(51, 16);
			this->label23->TabIndex = 3;
			this->label23->Text = L"label23";
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
			this->panel3->Controls->Add(this->label30);
			this->panel3->Controls->Add(this->label29);
			this->panel3->Controls->Add(this->label28);
			this->panel3->Controls->Add(this->label10);
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Controls->Add(this->label7);
			this->panel3->Location = System::Drawing::Point(635, 193);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(347, 135);
			this->panel3->TabIndex = 3;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->Location = System::Drawing::Point(106, 94);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(51, 16);
			this->label30->TabIndex = 6;
			this->label30->Text = L"label30";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->Location = System::Drawing::Point(106, 64);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(51, 16);
			this->label29->TabIndex = 5;
			this->label29->Text = L"label29";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->Location = System::Drawing::Point(282, 81);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(51, 16);
			this->label28->TabIndex = 4;
			this->label28->Text = L"label28";
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
			this->panel2->Controls->Add(this->label27);
			this->panel2->Controls->Add(this->label26);
			this->panel2->Controls->Add(this->label25);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Location = System::Drawing::Point(635, 43);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(347, 144);
			this->panel2->TabIndex = 2;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->Location = System::Drawing::Point(282, 97);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(51, 16);
			this->label27->TabIndex = 7;
			this->label27->Text = L"label27";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->Location = System::Drawing::Point(147, 97);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(51, 16);
			this->label26->TabIndex = 6;
			this->label26->Text = L"label26";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(12, 97);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(51, 16);
			this->label25->TabIndex = 5;
			this->label25->Text = L"label25";
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
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(799, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 9;
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox2_KeyPress);
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->BackColor = System::Drawing::SystemColors::Control;
			this->label35->Location = System::Drawing::Point(675, 7);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(118, 13);
			this->label35->TabIndex = 10;
			this->label35->Text = L"Please Enter City Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::Control;
			this->label2->Location = System::Drawing::Point(905, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::Control;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(973, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 7);
			this->label3->TabIndex = 13;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label36->Location = System::Drawing::Point(411, 240);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(0, 16);
			this->label36->TabIndex = 14;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(997, 597);
			this->Controls->Add(this->label36);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label35);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->SummaryPanel);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(1013, 636);
			this->MinimumSize = System::Drawing::Size(1013, 636);
			this->Name = L"MyForm";
			this->Text = L"Luke\'s Weather";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
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



	private: void updateSummaryPage() {

		label36->Text = "Error: No internet connection.";
		label36->Visible = false;
		SummaryPanel->Visible = true;


		label37->Text = GetCurrentTime();

		std::string urlDaily = "https://api.open-meteo.com/v1/forecast?latitude=" + url_encode(global->latitude) + "&longitude=" + url_encode(global->longitude) + "&daily=sunshine_duration&daily=sunrise&daily=sunset&daily=wind_speed_10m_max&daily=wind_gusts_10m_max&daily=wind_direction_10m_dominant&daily=uv_index_max&daily=uv_index_clear_sky_max&daily=precipitation_sum&daily=precipitation_probability_mean&daily=temperature_2m_min&daily=temperature_2m_max&daily=weather_code";
		//textBox2->Text = ConvertString(urlDaily.c_str());

		CURL* curl = curl_easy_init();
		if (curl) {
			std::string response;

			curl_easy_setopt(curl, CURLOPT_URL, urlDaily.c_str());
			WriteCallbackDelegate^ writeCallbackDelegate = gcnew WriteCallbackDelegate(&WriteCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallbackDelegate);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
			CURLcode res = curl_easy_perform(curl);
			if (res != CURLE_OK) {
				//label1->Text = "Error: " + curl_easy_strerror(res);
			}
			else {
				// Parse JSON response
				Json::Value jsonValue;
				Json::Reader jsonReader;
				if (jsonReader.parse(response, jsonValue)) {
					auto results = jsonValue["daily"];
					label22->Text = ConvertStringNoFormat(results["time"][0].asString()); //Displays the date
					label23->Text = ConvertString(results["precipitation_sum"][0].asString()) + " mm"; //Displays the precipitation sum
					label24->Text = ConvertString(results["precipitation_probability_mean"][0].asString()) + " %"; //Displays the precipitation probability

					label34->Text = ConvertString(results["temperature_2m_min"][0].asString()) + " °C"; //Displays the min temp
					label33->Text = ConvertString(results["temperature_2m_max"][0].asString()) + " °C";//Displays the max temp

					label32->Text = ConvertString(results["uv_index_clear_sky_max"][0].asString()); //Displays the clear sky max
					label31->Text = ConvertString(results["uv_index_max"][0].asString()); //Displays the max uv index

					label30->Text = ConvertString(results["wind_gusts_10m_max"][0].asString()) + " km/h"; //Displays the wind gusts
					label29->Text = ConvertString(results["wind_speed_10m_max"][0].asString()) + " km/h"; //Displays the wind speed
					label28->Text = GetWindDirection(results["wind_direction_10m_dominant"][0].asString()); //Displays the wind direction

					label27->Text = GetTimeFromTimestamp(results["sunset"][0].asString()); //Displays the sunset
					label25->Text = GetTimeFromTimestamp(results["sunrise"][0].asString()); //Displays the sunrise
					label26->Text = ConvertSecondsToHours(results["sunshine_duration"][0].asString()) + " hours"; //Displays the sunshine duration	

					label21->Text = GetWeatherDescription(results["weather_code"][0].asString()); //Displays the weather code
				}
				else {
					label1->Text = "Failed to parse JSON response.";
				}
			}
			curl_easy_cleanup(curl);
		}
	// Populating the Graph on Summary Page
		const std::string urlGraph("https://api.open-meteo.com/v1/forecast?latitude=" + url_encode(global->latitude) + "&longitude=" + url_encode(global->longitude) + "&minutely_15=temperature_2m");
		curl = curl_easy_init();
		if (curl) {
			std::string response;
			curl_easy_setopt(curl, CURLOPT_URL, urlGraph.c_str());
			WriteCallbackDelegate^ writeCallbackDelegate = gcnew WriteCallbackDelegate(&WriteCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallbackDelegate);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
			CURLcode res = curl_easy_perform(curl);
			if (res != CURLE_OK) {
				//label1->Text = "Error: " + curl_easy_strerror(res);
			}
			else {
				// Parse JSON response
				Json::Value jsonValue;
				Json::Reader jsonReader;
				if (jsonReader.parse(response, jsonValue)) {
					auto results = jsonValue["minutely_15"];
					auto timeData = results["time"];
					timeData.resize(96);
					auto temperatureData = results["temperature_2m"];
					temperatureData.resize(96);

					// Assuming 'chart1' is a System::Windows::Forms::DataVisualization::Charting::Chart
					chart1->Series->Clear(); // Clear existing data

					// Add a series for temperature data
					System::Windows::Forms::DataVisualization::Charting::Series^ temperatureSeries = gcnew System::Windows::Forms::DataVisualization::Charting::Series("Temperature");
					temperatureSeries->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;

					for (int i = 0; i < timeData.size(); ++i) {
						// Extract time and temperature for each data point
						System::String^ timeStr = GetTimeFromTimestamp(timeData[i].asString());
						double temperature = temperatureData[i].asDouble();
						if (i == 0) {
							System::String^ temp = ConvertStringNoFormat("00:00");
							temperatureSeries->Points->AddXY(temp, temperature);
						}

						// Add the data point to the chart
						temperatureSeries->Points->AddXY(timeStr, temperature);
					}

					// Add the temperature series to the chart
					chart1->Series->Add(temperatureSeries);

					// Calculate the minimum and maximum temperature values
					double minTemperature = DBL_MAX;
					double maxTemperature = -DBL_MAX;

					for (int i = 0; i < timeData.size(); ++i) {
						double temperature = temperatureData[i].asDouble();
						minTemperature = min(minTemperature, temperature);
						maxTemperature = max(maxTemperature, temperature);
					}

					// Set the Y-axis range based on the minimum and maximum temperatures
					chart1->ChartAreas[0]->AxisY->Minimum = minTemperature - 1; // You can adjust the padding if needed
					chart1->ChartAreas[0]->AxisY->Maximum = maxTemperature + 1; // You can adjust the padding if needed


					// Customize the chart appearance if needed
								// Customize the chart appearance if needed
					chart1->ChartAreas[0]->AxisX->Title = "Time";
					chart1->ChartAreas[0]->AxisY->Title = "Temperature (°C)";
					chart1->ChartAreas[0]->AxisX->LabelStyle->Interval = 4; // Set the interval to 1 for every data point
					chart1->ChartAreas[0]->AxisX->MajorGrid->Interval = 4; // Set the interval for major grid line
					chart1->Legends->Clear(); // Remove legends if not needed
				}
				else {
					//label1->Text = "Failed to parse JSON response.";
				}
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
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		SummaryPanel->Visible = true;
		// make other panels invisible
		menuStrip1->Visible = false;
		label1->Visible = false;

		label2->Text = ConvertString(global->city);
		updateSummaryPage();

	}
	private: System::Void textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == (char)13)
		{
			String ^ city = textBox2->Text;
			const std::string urlCity("https://api.opencagedata.com/geocode/v1/json?q="+url_encode(ConvertString(city))+"&key=8bf3c14897c3437cb44326acc120f27d");
			CURL* curl = curl_easy_init();
			curl = curl_easy_init();
			if (curl) {
				std::string response;
				curl_easy_setopt(curl, CURLOPT_URL, urlCity.c_str());
				WriteCallbackDelegate^ writeCallbackDelegate = gcnew WriteCallbackDelegate(&WriteCallback);
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallbackDelegate);
				curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
				CURLcode res = curl_easy_perform(curl);
				if (res != CURLE_OK) {
					//label1->Text = "Error: " + curl_easy_strerror(res);
				}
				else {
					// Parse JSON response
					Json::Value jsonValue;
					Json::Reader jsonReader;
					if (jsonReader.parse(response, jsonValue)) {
						auto results = jsonValue["results"];
						if (results.size() == 0) {
							label2->Text = "No results found.";
							label3->Text = ConvertString(jsonValue["rate"]["remaining"].asString());
							return;
						}
						global->city = ConvertString(textBox2->Text);
						label2->Text = ConvertString(global->city);
						auto geometry = results[0]["geometry"];
						global->latitude = geometry["lat"].asString();
						global->longitude = geometry["lng"].asString();
						label3->Text = ConvertString(jsonValue["rate"]["remaining"].asString());
						updateSummaryPage();
						
					}
					else {
						//label1->Text = "Failed to parse JSON response.";
					}
				}
			}
		}
	}
};
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


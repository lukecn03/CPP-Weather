#pragma once

#include <curl/curl.h>
#include <string>
#include <cstring>
#include <json/json.h>

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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;

	/*static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
	{
		((std::string*)userp)->append((char*)contents, size * nmemb);
		return size * nmemb;
	}*/

	public: delegate size_t callbackDelegate(const char* in,std::size_t size,std::size_t num,std::string* out) ;
	public: ref class Device {
		public: static std::size_t callback(
					const char* in,
					std::size_t size,
					std::size_t num,
					std::string* out)
			{
				const std::size_t totalBytes(size * num);
				out->append(in, totalBytes);
				return totalBytes;
			}

			// Add a static member function to serve as the callback for libcurl
		public: static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
			{
				return callback(static_cast<const char*>(contents), size, nmemb, static_cast<std::string*>(userp));
			}
	};

	public:
		delegate size_t WriteCallbackDelegate(void* contents, size_t size, size_t nmemb, void* userp);

		static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
		{
			return Device::callback(static_cast<const char*>(contents), size, nmemb, static_cast<std::string*>(userp));
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(202, 382);
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
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 25);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(474, 330);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(498, 412);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	

		//CURL* curl;
		//CURLcode res;
		//long http_code = 0;
		//std::string readBuffer;

		//curl = curl_easy_init();
		//if (curl) {
		//	curl_easy_setopt(curl, CURLOPT_URL, "https://api.open-meteo.com/v1/forecast?latitude=-26.520453&longitude=29.193603&hourly=temperature_2m&start_date=2023-12-13&end_date=2023-12-14");
		//	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		//	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

		//	/* Perform the request, res will get the return code */
		//	res = curl_easy_perform(curl);
		//	/* Check for errors */
		//	if (res != CURLE_OK)
		//		fprintf(stderr, "curl_easy_perform() failed: %s\n",
		//			curl_easy_strerror(res));
		//	else {
		//		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
		//	}

		//	/* always cleanup */
		//	curl_easy_cleanup(curl);
		//}


		const std::string url("https://api.open-meteo.com/v1/forecast?latitude=-26.520453&longitude=29.193603&hourly=temperature_2m&start_date=2023-12-13&end_date=2023-12-14");

		CURL* curl = curl_easy_init();

		// Set remote URL.
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

		// Don't bother trying IPv6, which would increase DNS resolution time.
		curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

		// Don't wait forever, time out after 10 seconds.
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

		// Follow HTTP redirects if necessary.
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		// Response information.
		long httpCode(0);
		std::unique_ptr<std::string> httpData(new std::string());



		// Hook up data handling function.
		WriteCallbackDelegate^ writeCallbackDelegate = gcnew WriteCallbackDelegate(&WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallbackDelegate);


		// Hook up data container (will be passed as the last parameter to the
		// callback handling function).  Can be any pointer type, since it will
		// internally be passed as a void pointer.
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

		// Run our HTTP GET command, capture the HTTP response code, and clean up.
		curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
		curl_easy_cleanup(curl);

		if (httpCode == 200)
		{
			label1->Text = "Got successful response from ";
		}

		// Now readBuffer contains the output JSON. You can parse it with JsonCpp:
		//Json::Value jsonData;
		//Json::Reader jsonReader;
		//if (jsonReader.parse(readBuffer, jsonData)) {
		//	// Successfully parsed JSON data
		//	// Now you can use jsonData to create your chart
		//}
		//else {
		//	// Failed to parse JSON
		//}

		/*std::string str = std::to_string(http_code);
		System::String^ result = gcnew System::String(str.c_str());
		label1->Text = result;*/
		
	}
	};
}

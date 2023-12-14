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
			this->button1->Location = System::Drawing::Point(115, 9);
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
			this->chart1->Location = System::Drawing::Point(15, 49);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(1433, 642);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(288, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(465, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1291, 19);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"label3";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1460, 714);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
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


		/*std::wstring city;
		System::String^ textBoxText = textBox1->Text;
		city = msclr::interop::marshal_as<std::wstring>(textBoxText);
		std::wstring apiUrl = L"https://api.opencagedata.com/geocode/v1/json?q=" + city + L"& key = 8bf3c14897c3437cb44326acc120f27d";*/

		const std::string url("https://api.opencagedata.com/geocode/v1/json?q=Secunda&key=8bf3c14897c3437cb44326acc120f27d");
		CURL* curl = curl_easy_init();
		if (curl) {
			std::string response;

			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
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
					if (!results.empty()) {
						auto location = results[0]["geometry"];
						double latitude = location["lat"].asDouble();
						double longitude = location["lng"].asDouble();
						label2->Text = "Latitude: " + latitude + "Longitude: " + longitude;
						label3->Text = gcnew System::String(jsonValue["rate"]["remaining"].asString().c_str()) + "/" +
							gcnew System::String(jsonValue["rate"]["limit"].asString().c_str()) +
							" Api limit remaining";

					}
					else {
						label1->Text = L"No results found for the city: ";
					}
				}
				else {
					label1->Text = "Failed to parse JSON response.";
				}
			}
			curl_easy_cleanup(curl);
		}




		const std::string urlWeather("https://api.open-meteo.com/v1/forecast?latitude=-26.520453&longitude=29.193603&hourly=temperature_2m");
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
			
			/*std::string str = std::to_string(httpCode);
			System::String^ result = gcnew System::String(str.c_str());
			label1->Text = result;*/

			chart1->Titles->Clear();
			chart1->Titles->Add("Temperature Forecast");

			// Now httpData contains the output JSON. You can parse it with JsonCpp:
			Json::Value jsonData;
			Json::Reader jsonReader;
			if (jsonReader.parse(*httpData, jsonData)) {
				// Successfully parsed JSON data
				
				// Assuming jsonData["timezone"] is a JSON value of type std::string
				std::string timezone = jsonData["timezone"].asString();
				// Convert std::string to System::String^
				System::String^ timezoneString = gcnew System::String(timezone.c_str());
				// Set the Text property of label1
				label1->Text = timezoneString;

				// Access latitude, longitude, and other information
				double latitude = jsonData["latitude"].asDouble();
				double longitude = jsonData["longitude"].asDouble();
				// Access hourly temperature data
				Json::Value hourlyData = jsonData["hourly"];
				Json::Value timeData = hourlyData["time"];
				Json::Value temperatureData = hourlyData["temperature_2m"];

				// Assuming 'chart1' is a System::Windows::Forms::DataVisualization::Charting::Chart
				chart1->Series->Clear(); // Clear existing data

				//// Add a series for temperature data
				//System::Windows::Forms::DataVisualization::Charting::Series^ temperatureSeries = gcnew System::Windows::Forms::DataVisualization::Charting::Series("Temperature");
				//temperatureSeries->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;

				//for (int i = 0; i < timeData.size(); ++i) {
				//	// Extract time and temperature for each data point
				//	System::DateTime^ dateTime = System::DateTime::Parse(gcnew System::String(timeData[i].asCString()));
				//	double temperature = temperatureData[i].asDouble();

				//	// Add the data point to the series
				//	temperatureSeries->Points->AddXY(dateTime, temperature);
				//}

				//// Add the temperature series to the chart
				//chart1->Series->Add(temperatureSeries);

				// Add a series for temperature data
				System::Windows::Forms::DataVisualization::Charting::Series^ temperatureSeries = gcnew System::Windows::Forms::DataVisualization::Charting::Series("Temperature");
				temperatureSeries->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;

				// Date for the previous data point to check for a new day
				System::DateTime^ prevDate = nullptr;
				for (int i = 0; i < timeData.size(); ++i) {
					// Extract time and temperature for each data point
					System::DateTime^ dateTime = System::DateTime::Parse(gcnew System::String(timeData[i].asCString()));
					double temperature = temperatureData[i].asDouble();

					// Check for a new day
					if (!prevDate || prevDate->Day != dateTime->Day) {
						//// Add a data point with bold day label
						//// Add a data point
						//temperatureSeries->Points->AddXY(dateTime, temperature);

						//// Get the last added point
						//int lastPointIndex = temperatureSeries->Points->Count - 1;
						//System::Windows::Forms::DataVisualization::Charting::DataPoint^ dataPoint = temperatureSeries->Points[lastPointIndex];

						//// Set the label and font of the data point
						//dataPoint->Label = dateTime->ToString("MM/dd");
						//dataPoint->Font = gcnew System::Drawing::Font("Arial", 8, System::Drawing::FontStyle::Bold);

					}
					else {
						// Add the data point with sub-label
						// Add a data point
						temperatureSeries->Points->AddXY(dateTime, temperature);

						// Get the last added point
						int lastPointIndex = temperatureSeries->Points->Count - 1;
						System::Windows::Forms::DataVisualization::Charting::DataPoint^ dataPoint = temperatureSeries->Points[lastPointIndex];

						// Set the label and font of the data point
						dataPoint->Label = dateTime->ToString("HH");
						dataPoint->Font = gcnew System::Drawing::Font("Arial", 6, System::Drawing::FontStyle::Regular);
					}

					// Update the previous date
					prevDate = dateTime;
				}

				// Add the temperature series to the chart
				chart1->Series->Add(temperatureSeries);

				// Customize the chart appearance if needed
				chart1->ChartAreas[0]->AxisX->Title = "Time";
				chart1->ChartAreas[0]->AxisY->Title = "Temperature (°C)";
				chart1->Legends->Clear(); // Remove legends if not needed
			}
			else {
				// Failed to parse JSON
			}
		}

	}
	};
}

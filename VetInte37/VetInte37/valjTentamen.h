#pragma once
#include "stdafx.h"

namespace Forms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::Common;
	using namespace System::Configuration;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for v�ljTentamen
	/// </summary>
	public ref class v�ljTentamen : public System::Windows::Forms::Form
	{
	public:

		DbCommand ^ _cmd;

		v�ljTentamen(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void setCmd(DbCommand ^ cmd)
		{
			_cmd = cmd;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~v�ljTentamen()
		{
			if (components)
			{
				delete components;
			}
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
			this->SuspendLayout();
			// 
			// v�ljTentamen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(653, 280);
			this->Name = L"v�ljTentamen";
			this->Text = L"v�ljTentamen";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

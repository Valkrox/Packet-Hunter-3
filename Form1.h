#pragma once

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used

#include "Header1.h"
#include "Header2.h"
#pragma comment(lib, "ws2_32.lib")

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Net;
    using namespace System::Net::Sockets;
    using namespace System::Text::RegularExpressions;


  /// <summary>
  /// Summary for Form1
  /// </summary>
  public ref class Form1 : public System::Windows::Forms::Form
  {
  private:
      Socket^ socketz;
      array<Byte>^ bytedata;
      IPAddress^ myip;
      bool started;
      bool formloaded;
      IPAddress^ FilterIPAddress;
      bool FilterIP;
      array<Net::NetworkInformation::NetworkInterface^>^ mycomputerconnections;
      String^ srsprot;
      String^ destprot;
      int checksumErrorsCount;
      int count;

      // DGV Update stuff
      String^ stringz;
      String^ Typez;
      IPAddress^ ipfrom;
      IPAddress^ ipto;
      UInt32 destinationport;
      UInt32 sourceport;
  private: System::Windows::Forms::Label^ label3;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^ Num;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^ Envoyeur;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^ Receveur;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^ srs;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^ dest;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^ type;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^ taille;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^ Données;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^ Uncryptz;
  private: System::Windows::Forms::ListView^ listView1;
  private: System::Windows::Forms::ColumnHeader^ columnHeader1;
  private: System::Windows::Forms::ColumnHeader^ columnHeader2;
  private: System::Windows::Forms::ColumnHeader^ columnHeader3;
  private: System::Windows::Forms::ColumnHeader^ columnHeader4;
  private: System::Windows::Forms::ColumnHeader^ columnHeader5;
  private: System::Windows::Forms::ColumnHeader^ columnHeader6;
  private: System::Windows::Forms::ColumnHeader^ columnHeader7;
  private: System::Windows::Forms::ColumnHeader^ columnHeader8;
  private: System::Windows::Forms::ColumnHeader^ columnHeader9;
  private: System::Windows::Forms::ColumnHeader^ columnHeader10;
  private: System::Windows::Forms::CheckBox^ checkBox1;
         String^ headerss;
  public:
    Form1(void)
    {
      InitializeComponent();
      formloaded = true; // Added formloaded initialization
      // Initialize your variables here
      socketz = gcnew Socket(AddressFamily::InterNetwork, SocketType::Raw, ProtocolType::IP);
      bytedata = gcnew array<Byte>(4096);
      started = true;
      FilterIPAddress = gcnew IPAddress(0);
      FilterIP = false;
      mycomputerconnections = Net::NetworkInformation::NetworkInterface::GetAllNetworkInterfaces();
      srsprot = "";
      destprot = "";
      checksumErrorsCount = 0;
      stringz = "";
      Typez = "";
      ipfrom = nullptr;
      ipto = nullptr;
      destinationport = 0;
      sourceport = 0;
      headerss = "";
      count = 0;

      // Populate ComboBox1 with network interface names
      for (int i = 0; i < mycomputerconnections->Length; i++) {
          comboBox1->Items->Add(mycomputerconnections[i]->Description);
      }

      // TODO: Initialize other components and event handlers
      //
      //TODO: Add the constructor code here
      //

      // uncomment to execute the rk1-utils:
      //    N_rk1_Utils_demo::execute(); // shows how the rk1-utils can be used

    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~Form1()
    {
      if (components)
      {
        delete components;
      }
    }
  private: System::Windows::Forms::Panel^ MainPanel;
  private: System::Windows::Forms::Panel^ panel1;
  private: System::Windows::Forms::MenuStrip^ menuStrip1;
  private: System::Windows::Forms::ToolStripMenuItem^ fichierToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ nouveauToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ ouvrirToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator;
  private: System::Windows::Forms::ToolStripMenuItem^ enregistrerToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ enregistrersousToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
  private: System::Windows::Forms::ToolStripMenuItem^ imprimerToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ aperçuavantimpressionToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
  private: System::Windows::Forms::ToolStripMenuItem^ quitterToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ editionToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ annulerToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ rétablirToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator3;
  private: System::Windows::Forms::ToolStripMenuItem^ couperToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ copierToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ collerToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator4;
  private: System::Windows::Forms::ToolStripMenuItem^ sélectionnertoutToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ outilsToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ personnaliserToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ optionsToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ aideToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ sommaireToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ indexToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ rechercherToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator5;
  private: System::Windows::Forms::ToolStripMenuItem^ àproposdeToolStripMenuItem;
  private: System::Windows::Forms::TabControl^ tabControl1;
  private: System::Windows::Forms::TabPage^ tabPage1;
  private: System::Windows::Forms::TabPage^ tabPage2;
  private: System::Windows::Forms::StatusStrip^ statusStrip1;
  private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
  private: System::Windows::Forms::Splitter^ splitter1;
  private: System::Windows::Forms::TabControl^ tabControl2;
  private: System::Windows::Forms::TabPage^ tabPage3;
  private: System::Windows::Forms::TabPage^ tabPage4;
  private: System::Windows::Forms::TabControl^ tabControl3;
  private: System::Windows::Forms::TabPage^ tabPage5;
  private: System::Windows::Forms::RichTextBox^ richTextBox1;











  private: System::Windows::Forms::TabPage^ tabPage6;
  private: System::Windows::Forms::ListBox^ listBox1;













  private: System::Windows::Forms::Button^ button1;
  private: System::Windows::Forms::TextBox^ textBox1;
  private: System::Windows::Forms::ComboBox^ comboBox1;
  private: System::Windows::Forms::Label^ label2;
  private: System::Windows::Forms::Label^ label1;
  internal: System::Windows::Forms::DataGridView^ DGV;
  private:










  protected:





  protected:

  private:
    /// <summary>
    /// Required designer variable.
    /// </summary>
    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void)
    {
        System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
        System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
        this->MainPanel = (gcnew System::Windows::Forms::Panel());
        this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
        this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
        this->listView1 = (gcnew System::Windows::Forms::ListView());
        this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
        this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
        this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
        this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
        this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
        this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
        this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
        this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
        this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
        this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
        this->DGV = (gcnew System::Windows::Forms::DataGridView());
        this->Num = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Envoyeur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Receveur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->srs = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dest = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->taille = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Données = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Uncryptz = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
        this->tabControl3 = (gcnew System::Windows::Forms::TabControl());
        this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
        this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
        this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
        this->listBox1 = (gcnew System::Windows::Forms::ListBox());
        this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
        this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
        this->splitter1 = (gcnew System::Windows::Forms::Splitter());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
        this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->textBox1 = (gcnew System::Windows::Forms::TextBox());
        this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
        this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
        this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
        this->fichierToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->nouveauToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->ouvrirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
        this->enregistrerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->enregistrersousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
        this->imprimerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->aperçuavantimpressionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
        this->quitterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->editionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->annulerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->rétablirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
        this->couperToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->copierToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->collerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
        this->sélectionnertoutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->outilsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->personnaliserToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->aideToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->sommaireToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->indexToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->rechercherToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
        this->àproposdeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->MainPanel->SuspendLayout();
        this->tabControl1->SuspendLayout();
        this->tabPage1->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGV))->BeginInit();
        this->tabPage2->SuspendLayout();
        this->tabControl3->SuspendLayout();
        this->tabPage5->SuspendLayout();
        this->tabPage6->SuspendLayout();
        this->statusStrip1->SuspendLayout();
        this->panel1->SuspendLayout();
        this->tabControl2->SuspendLayout();
        this->tabPage3->SuspendLayout();
        this->tabPage4->SuspendLayout();
        this->menuStrip1->SuspendLayout();
        this->SuspendLayout();
        // 
        // MainPanel
        // 
        this->MainPanel->AllowDrop = true;
        this->MainPanel->Controls->Add(this->tabControl1);
        this->MainPanel->Controls->Add(this->statusStrip1);
        this->MainPanel->Controls->Add(this->splitter1);
        this->MainPanel->Controls->Add(this->panel1);
        this->MainPanel->Controls->Add(this->menuStrip1);
        this->MainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
        this->MainPanel->Location = System::Drawing::Point(0, 0);
        this->MainPanel->Name = L"MainPanel";
        this->MainPanel->Size = System::Drawing::Size(1215, 598);
        this->MainPanel->TabIndex = 0;
        // 
        // tabControl1
        // 
        this->tabControl1->Controls->Add(this->tabPage1);
        this->tabControl1->Controls->Add(this->tabPage2);
        this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
        this->tabControl1->Location = System::Drawing::Point(0, 151);
        this->tabControl1->Name = L"tabControl1";
        this->tabControl1->SelectedIndex = 0;
        this->tabControl1->Size = System::Drawing::Size(1215, 425);
        this->tabControl1->TabIndex = 4;
        // 
        // tabPage1
        // 
        this->tabPage1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->tabPage1->Controls->Add(this->listView1);
        this->tabPage1->Controls->Add(this->DGV);
        this->tabPage1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tabPage1->ForeColor = System::Drawing::Color::White;
        this->tabPage1->Location = System::Drawing::Point(4, 22);
        this->tabPage1->Name = L"tabPage1";
        this->tabPage1->Padding = System::Windows::Forms::Padding(3);
        this->tabPage1->Size = System::Drawing::Size(1207, 399);
        this->tabPage1->TabIndex = 0;
        this->tabPage1->Text = L"Packet Hunter";
        // 
        // listView1
        // 
        this->listView1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->listView1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(10) {
            this->columnHeader1, this->columnHeader2,
                this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6, this->columnHeader7, this->columnHeader8,
                this->columnHeader9, this->columnHeader10
        });
        this->listView1->Dock = System::Windows::Forms::DockStyle::Fill;
        this->listView1->ForeColor = System::Drawing::Color::White;
        this->listView1->HideSelection = false;
        this->listView1->Location = System::Drawing::Point(3, 3);
        this->listView1->Name = L"listView1";
        this->listView1->Size = System::Drawing::Size(1201, 393);
        this->listView1->TabIndex = 3;
        this->listView1->UseCompatibleStateImageBehavior = false;
        this->listView1->View = System::Windows::Forms::View::Details;
        this->listView1->Visible = false;
        // 
        // columnHeader1
        // 
        this->columnHeader1->Text = L"Num";
        // 
        // columnHeader2
        // 
        this->columnHeader2->Text = L"Envoyeur";
        this->columnHeader2->Width = 182;
        // 
        // columnHeader3
        // 
        this->columnHeader3->Text = L"Receveur";
        this->columnHeader3->Width = 161;
        // 
        // columnHeader4
        // 
        this->columnHeader4->Text = L"Port source";
        this->columnHeader4->Width = 91;
        // 
        // columnHeader5
        // 
        this->columnHeader5->Text = L"Port destinataire";
        this->columnHeader5->Width = 112;
        // 
        // columnHeader6
        // 
        this->columnHeader6->Text = L"Service Source";
        this->columnHeader6->Width = 115;
        // 
        // columnHeader7
        // 
        this->columnHeader7->Text = L"Service destinataire";
        this->columnHeader7->Width = 143;
        // 
        // columnHeader8
        // 
        this->columnHeader8->Text = L"Protocole";
        this->columnHeader8->Width = 64;
        // 
        // columnHeader9
        // 
        this->columnHeader9->Text = L"Taille";
        // 
        // columnHeader10
        // 
        this->columnHeader10->Text = L"Données";
        this->columnHeader10->Width = 426;
        // 
        // DGV
        // 
        this->DGV->AllowUserToAddRows = false;
        this->DGV->AllowUserToDeleteRows = false;
        this->DGV->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->DGV->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
        dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
        dataGridViewCellStyle4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        dataGridViewCellStyle4->ForeColor = System::Drawing::Color::Lime;
        dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
        dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
        dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
        this->DGV->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
        this->DGV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
        this->DGV->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {
            this->Num, this->Envoyeur,
                this->Receveur, this->srs, this->dest, this->Column1, this->Column2, this->type, this->taille, this->Données, this->Uncryptz
        });
        dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
        dataGridViewCellStyle5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        dataGridViewCellStyle5->ForeColor = System::Drawing::Color::White;
        dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
        dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
        dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
        this->DGV->DefaultCellStyle = dataGridViewCellStyle5;
        this->DGV->Dock = System::Windows::Forms::DockStyle::Fill;
        this->DGV->EnableHeadersVisualStyles = false;
        this->DGV->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->DGV->Location = System::Drawing::Point(3, 3);
        this->DGV->Name = L"DGV";
        this->DGV->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
        dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
        dataGridViewCellStyle6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        dataGridViewCellStyle6->ForeColor = System::Drawing::Color::Lime;
        dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
        dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
        dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
        this->DGV->RowHeadersDefaultCellStyle = dataGridViewCellStyle6;
        this->DGV->RowHeadersVisible = false;
        this->DGV->RowHeadersWidth = 62;
        this->DGV->ShowCellErrors = false;
        this->DGV->ShowEditingIcon = false;
        this->DGV->ShowRowErrors = false;
        this->DGV->Size = System::Drawing::Size(1201, 393);
        this->DGV->TabIndex = 2;
        // 
        // Num
        // 
        this->Num->HeaderText = L"Num";
        this->Num->Name = L"Num";
        this->Num->Width = 50;
        // 
        // Envoyeur
        // 
        this->Envoyeur->HeaderText = L"Envoyeur";
        this->Envoyeur->MinimumWidth = 8;
        this->Envoyeur->Name = L"Envoyeur";
        this->Envoyeur->Width = 150;
        // 
        // Receveur
        // 
        this->Receveur->HeaderText = L"Receveur";
        this->Receveur->MinimumWidth = 8;
        this->Receveur->Name = L"Receveur";
        this->Receveur->Width = 150;
        // 
        // srs
        // 
        this->srs->HeaderText = L"Port source";
        this->srs->MinimumWidth = 8;
        this->srs->Name = L"srs";
        this->srs->Width = 150;
        // 
        // dest
        // 
        this->dest->HeaderText = L"Port destinataire";
        this->dest->MinimumWidth = 8;
        this->dest->Name = L"dest";
        this->dest->Width = 150;
        // 
        // Column1
        // 
        this->Column1->HeaderText = L"Protocole source";
        this->Column1->MinimumWidth = 8;
        this->Column1->Name = L"Column1";
        this->Column1->Width = 150;
        // 
        // Column2
        // 
        this->Column2->HeaderText = L"Protocole distant";
        this->Column2->MinimumWidth = 8;
        this->Column2->Name = L"Column2";
        this->Column2->Width = 150;
        // 
        // type
        // 
        this->type->HeaderText = L"Type (TCP/UDP)";
        this->type->MinimumWidth = 8;
        this->type->Name = L"type";
        this->type->Width = 150;
        // 
        // taille
        // 
        this->taille->HeaderText = L"Taille";
        this->taille->MinimumWidth = 8;
        this->taille->Name = L"taille";
        this->taille->Width = 60;
        // 
        // Données
        // 
        this->Données->HeaderText = L"Données";
        this->Données->MinimumWidth = 8;
        this->Données->Name = L"Données";
        this->Données->Width = 500;
        // 
        // Uncryptz
        // 
        this->Uncryptz->HeaderText = L"Column3";
        this->Uncryptz->Name = L"Uncryptz";
        // 
        // tabPage2
        // 
        this->tabPage2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->tabPage2->Controls->Add(this->tabControl3);
        this->tabPage2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tabPage2->Location = System::Drawing::Point(4, 22);
        this->tabPage2->Name = L"tabPage2";
        this->tabPage2->Padding = System::Windows::Forms::Padding(3);
        this->tabPage2->Size = System::Drawing::Size(1207, 399);
        this->tabPage2->TabIndex = 1;
        this->tabPage2->Text = L"Menaces";
        // 
        // tabControl3
        // 
        this->tabControl3->Alignment = System::Windows::Forms::TabAlignment::Bottom;
        this->tabControl3->Controls->Add(this->tabPage5);
        this->tabControl3->Controls->Add(this->tabPage6);
        this->tabControl3->Dock = System::Windows::Forms::DockStyle::Fill;
        this->tabControl3->Location = System::Drawing::Point(3, 3);
        this->tabControl3->Name = L"tabControl3";
        this->tabControl3->SelectedIndex = 0;
        this->tabControl3->Size = System::Drawing::Size(1201, 393);
        this->tabControl3->TabIndex = 0;
        // 
        // tabPage5
        // 
        this->tabPage5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->tabPage5->Controls->Add(this->richTextBox1);
        this->tabPage5->Location = System::Drawing::Point(4, 4);
        this->tabPage5->Name = L"tabPage5";
        this->tabPage5->Padding = System::Windows::Forms::Padding(3);
        this->tabPage5->Size = System::Drawing::Size(1193, 364);
        this->tabPage5->TabIndex = 0;
        this->tabPage5->Text = L"Menaces Actuelles";
        // 
        // richTextBox1
        // 
        this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
        this->richTextBox1->ForeColor = System::Drawing::Color::White;
        this->richTextBox1->Location = System::Drawing::Point(3, 3);
        this->richTextBox1->Name = L"richTextBox1";
        this->richTextBox1->Size = System::Drawing::Size(1187, 358);
        this->richTextBox1->TabIndex = 1;
        this->richTextBox1->Text = L"";
        // 
        // tabPage6
        // 
        this->tabPage6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->tabPage6->Controls->Add(this->listBox1);
        this->tabPage6->Location = System::Drawing::Point(4, 4);
        this->tabPage6->Name = L"tabPage6";
        this->tabPage6->Padding = System::Windows::Forms::Padding(3);
        this->tabPage6->Size = System::Drawing::Size(1193, 364);
        this->tabPage6->TabIndex = 1;
        this->tabPage6->Text = L"Historiques des menaces";
        // 
        // listBox1
        // 
        this->listBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->listBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->listBox1->Dock = System::Windows::Forms::DockStyle::Fill;
        this->listBox1->ForeColor = System::Drawing::Color::White;
        this->listBox1->FormattingEnabled = true;
        this->listBox1->ItemHeight = 16;
        this->listBox1->Location = System::Drawing::Point(3, 3);
        this->listBox1->Name = L"listBox1";
        this->listBox1->Size = System::Drawing::Size(1187, 358);
        this->listBox1->TabIndex = 1;
        // 
        // statusStrip1
        // 
        this->statusStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
        this->statusStrip1->Location = System::Drawing::Point(0, 576);
        this->statusStrip1->Name = L"statusStrip1";
        this->statusStrip1->Size = System::Drawing::Size(1215, 22);
        this->statusStrip1->TabIndex = 3;
        this->statusStrip1->Text = L"statusStrip1";
        // 
        // toolStripStatusLabel1
        // 
        this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
        this->toolStripStatusLabel1->Size = System::Drawing::Size(113, 17);
        this->toolStripStatusLabel1->Text = L"Application chargé !";
        // 
        // splitter1
        // 
        this->splitter1->Dock = System::Windows::Forms::DockStyle::Top;
        this->splitter1->Location = System::Drawing::Point(0, 148);
        this->splitter1->Name = L"splitter1";
        this->splitter1->Size = System::Drawing::Size(1215, 3);
        this->splitter1->TabIndex = 2;
        this->splitter1->TabStop = false;
        // 
        // panel1
        // 
        this->panel1->Controls->Add(this->tabControl2);
        this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel1->Location = System::Drawing::Point(0, 24);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(1215, 124);
        this->panel1->TabIndex = 0;
        // 
        // tabControl2
        // 
        this->tabControl2->Alignment = System::Windows::Forms::TabAlignment::Left;
        this->tabControl2->Controls->Add(this->tabPage3);
        this->tabControl2->Controls->Add(this->tabPage4);
        this->tabControl2->Dock = System::Windows::Forms::DockStyle::Fill;
        this->tabControl2->Location = System::Drawing::Point(0, 0);
        this->tabControl2->Multiline = true;
        this->tabControl2->Name = L"tabControl2";
        this->tabControl2->SelectedIndex = 0;
        this->tabControl2->Size = System::Drawing::Size(1215, 124);
        this->tabControl2->TabIndex = 0;
        // 
        // tabPage3
        // 
        this->tabPage3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->tabPage3->Controls->Add(this->label3);
        this->tabPage3->Controls->Add(this->button1);
        this->tabPage3->Controls->Add(this->textBox1);
        this->tabPage3->Controls->Add(this->comboBox1);
        this->tabPage3->Controls->Add(this->label2);
        this->tabPage3->Controls->Add(this->label1);
        this->tabPage3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tabPage3->Location = System::Drawing::Point(23, 4);
        this->tabPage3->Name = L"tabPage3";
        this->tabPage3->Padding = System::Windows::Forms::Padding(3);
        this->tabPage3->Size = System::Drawing::Size(1188, 116);
        this->tabPage3->TabIndex = 0;
        this->tabPage3->Text = L"Actions";
        // 
        // label3
        // 
        this->label3->AutoSize = true;
        this->label3->Location = System::Drawing::Point(748, 7);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(165, 16);
        this->label3->TabIndex = 5;
        this->label3->Text = L"Nombres de paquets traiter : 0";
        // 
        // button1
        // 
        this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
        this->button1->Location = System::Drawing::Point(492, 27);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(137, 23);
        this->button1->TabIndex = 4;
        this->button1->Text = L"Stop";
        this->button1->UseVisualStyleBackColor = true;
        this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
        // 
        // textBox1
        // 
        this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        this->textBox1->ForeColor = System::Drawing::Color::White;
        this->textBox1->Location = System::Drawing::Point(87, 44);
        this->textBox1->Name = L"textBox1";
        this->textBox1->Size = System::Drawing::Size(399, 21);
        this->textBox1->TabIndex = 3;
        this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
        // 
        // comboBox1
        // 
        this->comboBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
        this->comboBox1->ForeColor = System::Drawing::Color::White;
        this->comboBox1->FormattingEnabled = true;
        this->comboBox1->Location = System::Drawing::Point(87, 14);
        this->comboBox1->Name = L"comboBox1";
        this->comboBox1->Size = System::Drawing::Size(399, 24);
        this->comboBox1->TabIndex = 2;
        this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
        // 
        // label2
        // 
        this->label2->AutoSize = true;
        this->label2->Location = System::Drawing::Point(6, 44);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(55, 16);
        this->label2->TabIndex = 1;
        this->label2->Text = L"Filtre IP : ";
        // 
        // label1
        // 
        this->label1->AutoSize = true;
        this->label1->Location = System::Drawing::Point(6, 17);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(75, 16);
        this->label1->TabIndex = 0;
        this->label1->Text = L"Adaptateur : ";
        // 
        // tabPage4
        // 
        this->tabPage4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->tabPage4->Controls->Add(this->checkBox1);
        this->tabPage4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->tabPage4->Location = System::Drawing::Point(23, 4);
        this->tabPage4->Name = L"tabPage4";
        this->tabPage4->Padding = System::Windows::Forms::Padding(3);
        this->tabPage4->Size = System::Drawing::Size(1188, 116);
        this->tabPage4->TabIndex = 1;
        this->tabPage4->Text = L"Options";
        // 
        // checkBox1
        // 
        this->checkBox1->AutoSize = true;
        this->checkBox1->Location = System::Drawing::Point(7, 7);
        this->checkBox1->Name = L"checkBox1";
        this->checkBox1->Size = System::Drawing::Size(117, 20);
        this->checkBox1->TabIndex = 0;
        this->checkBox1->Text = L"Affichage avancé";
        this->checkBox1->UseVisualStyleBackColor = true;
        this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
        // 
        // menuStrip1
        // 
        this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
            this->fichierToolStripMenuItem,
                this->editionToolStripMenuItem, this->outilsToolStripMenuItem, this->aideToolStripMenuItem
        });
        this->menuStrip1->Location = System::Drawing::Point(0, 0);
        this->menuStrip1->Name = L"menuStrip1";
        this->menuStrip1->Size = System::Drawing::Size(1215, 24);
        this->menuStrip1->TabIndex = 1;
        this->menuStrip1->Text = L"menuStrip1";
        // 
        // fichierToolStripMenuItem
        // 
        this->fichierToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
            this->nouveauToolStripMenuItem,
                this->ouvrirToolStripMenuItem, this->toolStripSeparator, this->enregistrerToolStripMenuItem, this->enregistrersousToolStripMenuItem,
                this->toolStripSeparator1, this->imprimerToolStripMenuItem, this->aperçuavantimpressionToolStripMenuItem, this->toolStripSeparator2,
                this->quitterToolStripMenuItem
        });
        this->fichierToolStripMenuItem->ForeColor = System::Drawing::Color::White;
        this->fichierToolStripMenuItem->Name = L"fichierToolStripMenuItem";
        this->fichierToolStripMenuItem->Size = System::Drawing::Size(54, 20);
        this->fichierToolStripMenuItem->Text = L"&Fichier";
        // 
        // nouveauToolStripMenuItem
        // 
        this->nouveauToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
        this->nouveauToolStripMenuItem->Name = L"nouveauToolStripMenuItem";
        this->nouveauToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
        this->nouveauToolStripMenuItem->Size = System::Drawing::Size(205, 22);
        this->nouveauToolStripMenuItem->Text = L"&Nouveau";
        // 
        // ouvrirToolStripMenuItem
        // 
        this->ouvrirToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
        this->ouvrirToolStripMenuItem->Name = L"ouvrirToolStripMenuItem";
        this->ouvrirToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
        this->ouvrirToolStripMenuItem->Size = System::Drawing::Size(205, 22);
        this->ouvrirToolStripMenuItem->Text = L"&Ouvrir";
        // 
        // toolStripSeparator
        // 
        this->toolStripSeparator->Name = L"toolStripSeparator";
        this->toolStripSeparator->Size = System::Drawing::Size(202, 6);
        // 
        // enregistrerToolStripMenuItem
        // 
        this->enregistrerToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
        this->enregistrerToolStripMenuItem->Name = L"enregistrerToolStripMenuItem";
        this->enregistrerToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
        this->enregistrerToolStripMenuItem->Size = System::Drawing::Size(205, 22);
        this->enregistrerToolStripMenuItem->Text = L"&Enregistrer";
        // 
        // enregistrersousToolStripMenuItem
        // 
        this->enregistrersousToolStripMenuItem->Name = L"enregistrersousToolStripMenuItem";
        this->enregistrersousToolStripMenuItem->Size = System::Drawing::Size(205, 22);
        this->enregistrersousToolStripMenuItem->Text = L"Enregistrer &sous";
        // 
        // toolStripSeparator1
        // 
        this->toolStripSeparator1->Name = L"toolStripSeparator1";
        this->toolStripSeparator1->Size = System::Drawing::Size(202, 6);
        // 
        // imprimerToolStripMenuItem
        // 
        this->imprimerToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
        this->imprimerToolStripMenuItem->Name = L"imprimerToolStripMenuItem";
        this->imprimerToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
        this->imprimerToolStripMenuItem->Size = System::Drawing::Size(205, 22);
        this->imprimerToolStripMenuItem->Text = L"&Imprimer";
        // 
        // aperçuavantimpressionToolStripMenuItem
        // 
        this->aperçuavantimpressionToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
        this->aperçuavantimpressionToolStripMenuItem->Name = L"aperçuavantimpressionToolStripMenuItem";
        this->aperçuavantimpressionToolStripMenuItem->Size = System::Drawing::Size(205, 22);
        this->aperçuavantimpressionToolStripMenuItem->Text = L"Aperçu a&vant impression";
        // 
        // toolStripSeparator2
        // 
        this->toolStripSeparator2->Name = L"toolStripSeparator2";
        this->toolStripSeparator2->Size = System::Drawing::Size(202, 6);
        // 
        // quitterToolStripMenuItem
        // 
        this->quitterToolStripMenuItem->Name = L"quitterToolStripMenuItem";
        this->quitterToolStripMenuItem->Size = System::Drawing::Size(205, 22);
        this->quitterToolStripMenuItem->Text = L"&Quitter";
        // 
        // editionToolStripMenuItem
        // 
        this->editionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
            this->annulerToolStripMenuItem,
                this->rétablirToolStripMenuItem, this->toolStripSeparator3, this->couperToolStripMenuItem, this->copierToolStripMenuItem, this->collerToolStripMenuItem,
                this->toolStripSeparator4, this->sélectionnertoutToolStripMenuItem
        });
        this->editionToolStripMenuItem->ForeColor = System::Drawing::Color::White;
        this->editionToolStripMenuItem->Name = L"editionToolStripMenuItem";
        this->editionToolStripMenuItem->Size = System::Drawing::Size(56, 20);
        this->editionToolStripMenuItem->Text = L"&Edition";
        // 
        // annulerToolStripMenuItem
        // 
        this->annulerToolStripMenuItem->Name = L"annulerToolStripMenuItem";
        this->annulerToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
        this->annulerToolStripMenuItem->Size = System::Drawing::Size(164, 22);
        this->annulerToolStripMenuItem->Text = L"&Annuler";
        // 
        // rétablirToolStripMenuItem
        // 
        this->rétablirToolStripMenuItem->Name = L"rétablirToolStripMenuItem";
        this->rétablirToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Y));
        this->rétablirToolStripMenuItem->Size = System::Drawing::Size(164, 22);
        this->rétablirToolStripMenuItem->Text = L"&Rétablir";
        // 
        // toolStripSeparator3
        // 
        this->toolStripSeparator3->Name = L"toolStripSeparator3";
        this->toolStripSeparator3->Size = System::Drawing::Size(161, 6);
        // 
        // couperToolStripMenuItem
        // 
        this->couperToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
        this->couperToolStripMenuItem->Name = L"couperToolStripMenuItem";
        this->couperToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
        this->couperToolStripMenuItem->Size = System::Drawing::Size(164, 22);
        this->couperToolStripMenuItem->Text = L"&Couper";
        // 
        // copierToolStripMenuItem
        // 
        this->copierToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
        this->copierToolStripMenuItem->Name = L"copierToolStripMenuItem";
        this->copierToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
        this->copierToolStripMenuItem->Size = System::Drawing::Size(164, 22);
        this->copierToolStripMenuItem->Text = L"Co&pier";
        // 
        // collerToolStripMenuItem
        // 
        this->collerToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
        this->collerToolStripMenuItem->Name = L"collerToolStripMenuItem";
        this->collerToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
        this->collerToolStripMenuItem->Size = System::Drawing::Size(164, 22);
        this->collerToolStripMenuItem->Text = L"Co&ller";
        // 
        // toolStripSeparator4
        // 
        this->toolStripSeparator4->Name = L"toolStripSeparator4";
        this->toolStripSeparator4->Size = System::Drawing::Size(161, 6);
        // 
        // sélectionnertoutToolStripMenuItem
        // 
        this->sélectionnertoutToolStripMenuItem->Name = L"sélectionnertoutToolStripMenuItem";
        this->sélectionnertoutToolStripMenuItem->Size = System::Drawing::Size(164, 22);
        this->sélectionnertoutToolStripMenuItem->Text = L"Sélectio&nner tout";
        // 
        // outilsToolStripMenuItem
        // 
        this->outilsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
            this->personnaliserToolStripMenuItem,
                this->optionsToolStripMenuItem
        });
        this->outilsToolStripMenuItem->ForeColor = System::Drawing::Color::White;
        this->outilsToolStripMenuItem->Name = L"outilsToolStripMenuItem";
        this->outilsToolStripMenuItem->Size = System::Drawing::Size(50, 20);
        this->outilsToolStripMenuItem->Text = L"&Outils";
        // 
        // personnaliserToolStripMenuItem
        // 
        this->personnaliserToolStripMenuItem->Name = L"personnaliserToolStripMenuItem";
        this->personnaliserToolStripMenuItem->Size = System::Drawing::Size(144, 22);
        this->personnaliserToolStripMenuItem->Text = L"&Personnaliser";
        // 
        // optionsToolStripMenuItem
        // 
        this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
        this->optionsToolStripMenuItem->Size = System::Drawing::Size(144, 22);
        this->optionsToolStripMenuItem->Text = L"&Options";
        // 
        // aideToolStripMenuItem
        // 
        this->aideToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
            this->sommaireToolStripMenuItem,
                this->indexToolStripMenuItem, this->rechercherToolStripMenuItem, this->toolStripSeparator5, this->àproposdeToolStripMenuItem
        });
        this->aideToolStripMenuItem->ForeColor = System::Drawing::Color::White;
        this->aideToolStripMenuItem->Name = L"aideToolStripMenuItem";
        this->aideToolStripMenuItem->Size = System::Drawing::Size(43, 20);
        this->aideToolStripMenuItem->Text = L"&Aide";
        // 
        // sommaireToolStripMenuItem
        // 
        this->sommaireToolStripMenuItem->Name = L"sommaireToolStripMenuItem";
        this->sommaireToolStripMenuItem->Size = System::Drawing::Size(147, 22);
        this->sommaireToolStripMenuItem->Text = L"&Sommaire";
        // 
        // indexToolStripMenuItem
        // 
        this->indexToolStripMenuItem->Name = L"indexToolStripMenuItem";
        this->indexToolStripMenuItem->Size = System::Drawing::Size(147, 22);
        this->indexToolStripMenuItem->Text = L"&Index";
        // 
        // rechercherToolStripMenuItem
        // 
        this->rechercherToolStripMenuItem->Name = L"rechercherToolStripMenuItem";
        this->rechercherToolStripMenuItem->Size = System::Drawing::Size(147, 22);
        this->rechercherToolStripMenuItem->Text = L"&Rechercher";
        // 
        // toolStripSeparator5
        // 
        this->toolStripSeparator5->Name = L"toolStripSeparator5";
        this->toolStripSeparator5->Size = System::Drawing::Size(144, 6);
        // 
        // àproposdeToolStripMenuItem
        // 
        this->àproposdeToolStripMenuItem->Name = L"àproposdeToolStripMenuItem";
        this->àproposdeToolStripMenuItem->Size = System::Drawing::Size(147, 22);
        this->àproposdeToolStripMenuItem->Text = L"À &propos de...";
        // 
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
            static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->ClientSize = System::Drawing::Size(1215, 598);
        this->Controls->Add(this->MainPanel);
        this->ForeColor = System::Drawing::Color::White;
        this->MainMenuStrip = this->menuStrip1;
        this->Name = L"Form1";
        this->Opacity = 0.99;
        this->ShowIcon = false;
        this->Text = L"Code 0 Packet Hunter V3";
        this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
        this->MainPanel->ResumeLayout(false);
        this->MainPanel->PerformLayout();
        this->tabControl1->ResumeLayout(false);
        this->tabPage1->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGV))->EndInit();
        this->tabPage2->ResumeLayout(false);
        this->tabControl3->ResumeLayout(false);
        this->tabPage5->ResumeLayout(false);
        this->tabPage6->ResumeLayout(false);
        this->statusStrip1->ResumeLayout(false);
        this->statusStrip1->PerformLayout();
        this->panel1->ResumeLayout(false);
        this->tabControl2->ResumeLayout(false);
        this->tabPage3->ResumeLayout(false);
        this->tabPage3->PerformLayout();
        this->tabPage4->ResumeLayout(false);
        this->tabPage4->PerformLayout();
        this->menuStrip1->ResumeLayout(false);
        this->menuStrip1->PerformLayout();
        this->ResumeLayout(false);

    }
#pragma endregion

   // You can call the functions at a button click. If you prefer, 
    // you can call them by clicking a menu item.
    void OnReceive(IAsyncResult^ asyncresult)
    {
        if (started)
        {
            // Get Length of packet (including header)
            UInt32 readlength = BitConverter::ToUInt16(Byteswap(bytedata, 2), 0);
            sourceport = BitConverter::ToUInt16(Byteswap(bytedata, 22), 0);
            destinationport = BitConverter::ToUInt16(Byteswap(bytedata, 24), 0);

            // Get Protocol Type
            if (bytedata[9] == 6)
            {
                Typez = "TCP";
            }
            else if (bytedata[9] == 17)
            {
                Typez = "UDP";
            }
            else
            {
                Typez = "???";
            }

            // Get IP from and to
            ipfrom = gcnew IPAddress(BitConverter::ToUInt32(bytedata, 12));
            ipto = gcnew IPAddress(BitConverter::ToUInt32(bytedata, 16));

            // If this is a packet to/from me and not from myself then...
            if ((ipfrom->Equals(myip) || ipto->Equals(myip)) && !ipto->Equals(ipfrom))
            {
                if (!FilterIP || (FilterIP && (FilterIPAddress->Equals(ipfrom) || FilterIPAddress->Equals(ipto))))
                {
                    // Fix data
                    stringz = "";
                    for (int i = 26; i < readlength; i++)
                    {
                        if (Char::IsLetterOrDigit((Char)bytedata[i]))
                        {
                            stringz += (Char)bytedata[i];
                        }
                        else
                        {
                            stringz += ".";
                        }
                    }
                        // Put data to DataGridView without headers
                        this->Invoke(gcnew Action(this, &Form1::DGVUpdate));
                    
                }
            }
        }

        // Restart the Receiving
        socketz->BeginReceive(bytedata, 0, bytedata->Length, SocketFlags::None, gcnew AsyncCallback(this, &Form1::OnReceive), nullptr);
    }

    array<Byte>^ Byteswap(array<Byte>^ bytez, UInt32 index)
    {
        array<Byte>^ result = gcnew array<Byte>(2);
        result[0] = bytez[index + 1];
        result[1] = bytez[index];
        return result;
    }

    void DGVUpdate()
    {
        String^ srsprot = "";
        String^ destprot = "";
        count++;
        label3->Text = "Nombres de paquets traiter : " + count.ToString();

        // Supprimer les lignes si elles sont trop nombreuses
        if (DGV->Rows->Count > 50)
        {
            DGV->Rows->RemoveAt(0);
        }

        if (sourceport == 22)
        {
            if (Typez = "TCP") {
                srsprot = "SSH";
            }
        }

        if (destinationport == 22)
        {
            if (Typez = "TCP") {
                destprot = "SSH";
            }
        }

        if (sourceport == 23)
        {
            if (Typez = "TCP") {
                srsprot = "Telnet";
            }
        }

        if (destinationport == 22)
        {
            if (Typez = "TCP") {
                destprot = "Telnet";
            }
        }

        if (sourceport == 80)
        {
            if (Typez = "TCP") {
                srsprot = "HTTP";
            }
        }

        if (destinationport == 80)
        {
            if (Typez = "TCP") {
                destprot = "HTTP";
            }
        }

        if (sourceport == 443)
        {
            if (Typez = "TCP") {
                srsprot = "HTTPS";
            }
        }

        if (destinationport == 443)
        {
            if (Typez = "TCP") {
                destprot = "HTTPS";
            }
        }
        if (listView1->Visible == true) {
            listView1->Items->Add(count.ToString());
            listView1->Items[listView1->Items->Count - 1]->SubItems->Add(ipfrom->ToString());
            listView1->Items[listView1->Items->Count - 1]->SubItems->Add(ipto->ToString());
            listView1->Items[listView1->Items->Count - 1]->SubItems->Add(sourceport.ToString());
            listView1->Items[listView1->Items->Count - 1]->SubItems->Add(destinationport.ToString());
            listView1->Items[listView1->Items->Count - 1]->SubItems->Add(srsprot);
            listView1->Items[listView1->Items->Count - 1]->SubItems->Add(destprot);
            listView1->Items[listView1->Items->Count - 1]->SubItems->Add(Typez);
            listView1->Items[listView1->Items->Count - 1]->SubItems->Add("");
            listView1->Items[listView1->Items->Count - 1]->SubItems->Add(stringz);
            listView1->Items[listView1->Items->Count - 1]->EnsureVisible();
            if (srsprot == "Exeample") {
                listView1->Items[listView1->Items->Count - 1]->BackColor = Color::Green;
            }
        }
        else
        {
            DGV->Rows->Add();
            DGV->Rows[DGV->Rows->Count - 1]->Cells[0]->Value = count.ToString();
            DGV->Rows[DGV->Rows->Count - 1]->Cells[1]->Value = ipfrom->ToString();
            DGV->Rows[DGV->Rows->Count - 1]->Cells[2]->Value = ipto->ToString();
            DGV->Rows[DGV->Rows->Count - 1]->Cells[3]->Value = sourceport;
            DGV->Rows[DGV->Rows->Count - 1]->Cells[4]->Value = destinationport;
            DGV->Rows[DGV->Rows->Count - 1]->Cells[5]->Value = srsprot;
            DGV->Rows[DGV->Rows->Count - 1]->Cells[6]->Value = destprot;
            DGV->Rows[DGV->Rows->Count - 1]->Cells[7]->Value = Typez;
            DGV->Rows[DGV->Rows->Count - 1]->Cells[9]->Value = stringz;
        }
    }

  private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
      try
      {
          if (textBox1->Text != nullptr && textBox1->Text != "")
          {
              FilterIPAddress = IPAddress::Parse(textBox1->Text);
              FilterIP = true;
              textBox1->BackColor = Color::LimeGreen;
          }
          else
          {
              FilterIP = false;
              textBox1->BackColor = Color::White;
          }
      }
      catch (Exception^ ex)
      {
          FilterIP = false;
          textBox1->BackColor = Color::White;
      }
  }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    if (mycomputerconnections != nullptr && comboBox1->SelectedIndex >= 0 && comboBox1->SelectedIndex < mycomputerconnections->Length)
    {
        for (int i = 0; i < mycomputerconnections[comboBox1->SelectedIndex]->GetIPProperties()->UnicastAddresses->Count; i++)
        {
            if (mycomputerconnections[comboBox1->SelectedIndex]->GetIPProperties()->UnicastAddresses[i]->Address->AddressFamily == AddressFamily::InterNetwork)
            {
                myip = mycomputerconnections[comboBox1->SelectedIndex]->GetIPProperties()->UnicastAddresses[i]->Address;
                BindSocket();
            }
        }
    }
}

       void BindSocket()
       {
           try
           {
               socketz->Bind(gcnew IPEndPoint(myip, 0));
               socketz->SetSocketOption(SocketOptionLevel::IP, SocketOptionName::HeaderIncluded, true);
               array<Byte>^ bytrue = { 1, 0, 0, 0 };
               array<Byte>^ byout = { 1, 0, 0, 0 };
               socketz->IOControl(IOControlCode::ReceiveAll, bytrue, byout);
               socketz->Blocking = false;
               bytedata = gcnew array<Byte>(socketz->ReceiveBufferSize);
               socketz->BeginReceive(bytedata, 0, bytedata->Length, SocketFlags::None, gcnew AsyncCallback(this, &Form1::OnReceive), nullptr);
               comboBox1->Enabled = false;
           }
           catch (Exception^ ex)
           {
               comboBox1->BackColor = Color::Red;
           }
       }
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    if (started)
    {
        button1->Text = "Start";
        started = false;
    }
    else
    {
        button1->Text = "Stop";
        started = true;
    }
}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
    if (checkBox1->Checked == true) {
        listView1->Visible = true;
    }
    else
    {
        listView1->Visible = false;
    }
}
}; // end of class Form1
} // end of namespace CppCLRWinFormsProject


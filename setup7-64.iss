; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "ChessX"
#define MyAppVersion "1.6.2"
#define MyAppPublisher "chessx.sourceforge.net"
#define MyAppURL "http://chessx.sourceforge.net"
#define MyAppExeName "chessx.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{8EB04E4D-9D75-4663-AAB2-ED6F742BEA61}}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={commonpf}\{#MyAppName}
DefaultGroupName={#MyAppName}
DisableWelcomePage=no
AllowNoIcons=yes
LicenseFile=.\COPYING.md
InfoAfterFile=.\ChangeLog.md
OutputBaseFilename=setup-chessx7-64
OutputDir=Packages
SetupIconFile=.\src\chessx.ico
Compression=lzma
SolidCompression=yes
ChangesAssociations = yes
ArchitecturesAllowed = x64 ia64
ArchitecturesInstallIn64BitMode = x64 ia64

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; OnlyBelowVersion: 0,6.1

[Files]
Source: "release\chessx.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "release\*.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "release\chessx.exe.local"; DestDir: "{app}"; Flags: ignoreversion
Source: ".\COPYING.md"; DestDir: "{app}"; Flags: ignoreversion
Source: ".\ChangeLog.md"; DestDir: "{app}"
Source: ".\data\engines\uci\stockfish_10_x64.exe"; DestDir: "{app}\data\engines\uci\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: ".\data\timeseal\windows\*.exe"; DestDir: "{app}\data\timeseal\windows\"; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commonstartup}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

[Tasks]
Name: pgnAssociation; Description: "Associate ""pgn"" extension"; GroupDescription: File extensions:

[Registry]
Root: HKCR; Subkey: ".pgn";                             ValueData: "{#MyAppName}";          Flags: uninsdeletevalue; ValueType: string;  ValueName: ""; Tasks: pgnAssociation
Root: HKCR; Subkey: "{#MyAppName}";                     ValueData: "Program {#MyAppName}";  Flags: uninsdeletekey;   ValueType: string;  ValueName: ""; Tasks: pgnAssociation
Root: HKCR; Subkey: "{#MyAppName}\DefaultIcon";         ValueData: "{app}\{#MyAppExeName},0";                        ValueType: string;  ValueName: ""; Tasks: pgnAssociation
Root: HKCR; Subkey: "{#MyAppName}\shell\open\command";  ValueData: """{app}\{#MyAppExeName}"" ""%1""";               ValueType: string;  ValueName: ""; Tasks: pgnAssociation

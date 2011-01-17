#include "stdafx.h"
#include "OutputFormat.h"
#include "ProtossCommand.h"
#include "TerranCommand.h"
#include "ZergCommand.h"

template<> void GetInitialYABOTOutput<EProtossCommand>(CString &output)
{
	output.AppendFormat(L"        <Key name=\"BuildOrder1\">\r\n            <Value string=\"100 [i] scbuidlorderresult | 7 | SCBuildOrder | Build order developed by SCBuildOder [/i] [s] ");
}

template<> void GetInitialYABOTOutput<ETerranCommand>(CString &output)
{
	output.AppendFormat(L"        <Key name=\"BuildOrder1\">\r\n            <Value string=\"100 [i] scbuidlorderresult | 3 | SCBuildOrder | Build order developed by SCBuildOder [/i] [s] ");
}

template<> void GetInitialYABOTOutput<EZergCommand>(CString &output)
{
	output.AppendFormat(L"        <Key name=\"BuildOrder1\">\r\n            <Value string=\"100 [i] scbuidlorderresult | 11 | SCBuildOrder | Build order developed by SCBuildOder [/i] [s] ");
}

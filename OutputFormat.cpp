#include "stdafx.h"
#include "OutputFormat.h"
#include "ProtossCommand.h"
#include "TerranCommand.h"
#include "ZergCommand.h"

template<> void GetInitialYABOTOutput<EProtossCommand>(CString &output)
{
	output.AppendFormat(L"100 [i] scbuildorderresult | 7 | SCBuildOrder | Build order developed by SCBuildOrder [/i] [s] ");
}

template<> void GetInitialYABOTOutput<ETerranCommand>(CString &output)
{
	output.AppendFormat(L"100 [i] scbuildorderresult | 3 | SCBuildOrder | Build order developed by SCBuildOrder [/i] [s] ");
}

template<> void GetInitialYABOTOutput<EZergCommand>(CString &output)
{
	output.AppendFormat(L"100 [i] scbuildorderresult | 11 | SCBuildOrder | Build order developed by SCBuildOrder [/i] [s] ");
}

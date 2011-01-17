#pragma once

enum EOutputFormat
{
	eOutputFormatSimple
	, eOutputFormatDetailed
	, eOutputFormatFull
	, eOutputFormatHaploid
	, eOutputFormatYABOT
	, eOutputFormatSC2Gears
};

template <typename TCommand>
void GetInitialYABOTOutput(CString &output);

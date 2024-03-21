#pragma once

struct vector_t {
	float x, y, z;
};

class jump_settings_t {

	public:
		char pad_0x0000[0x10]; //0x0000
		float JumpForce;
		float ForwardVelocityMultiplier;
		float JumpHoldForce;
		float AirJumpGraceTime;
		float InAirJumpForce;
		float InAirForwardVelocityMultiplier;
		float FromDodgeJumpForce;
		float FromDodgeForwardVelocityMultiplier;
		float TriggerSoarTime;
		float CameraLookInfluence;
		vector_t InputMovementInfluence;

};


/*<Elements>
<Element Offset = "16" Vartype = "Float" Bytesize = "4" OffsetHex = "00000010" Description = "JumpForce" DisplayMethod = "unsigned integer" / >
<Element Offset = "20" Vartype = "Float" Bytesize = "4" OffsetHex = "00000014" Description = "ForwardVelocityMultiplier" DisplayMethod = "unsigned integer" / >
<Element Offset = "24" Vartype = "Float" Bytesize = "4" OffsetHex = "00000018" Description = "JumpHoldForce" DisplayMethod = "unsigned integer" / >
<Element Offset = "28" Vartype = "Float" Bytesize = "4" OffsetHex = "0000001C" Description = "AirJumpGraceTime" DisplayMethod = "unsigned integer" / >
<Element Offset = "32" Vartype = "Float" Bytesize = "4" OffsetHex = "00000020" Description = "InAirJumpForce" DisplayMethod = "unsigned integer" / >
<Element Offset = "36" Vartype = "Float" Bytesize = "4" OffsetHex = "00000024" Description = "InAirForwardVelocityMultiplier" DisplayMethod = "unsigned integer" / >
<Element Offset = "40" Vartype = "Float" Bytesize = "4" OffsetHex = "00000028" Description = "FromDodgeJumpForce" DisplayMethod = "unsigned integer" / >
<Element Offset = "44" Vartype = "Float" Bytesize = "4" OffsetHex = "0000002C" Description = "FromDodgeForwardVelocityMultiplier" DisplayMethod = "unsigned integer" / >
<Element Offset = "48" Vartype = "Float" Bytesize = "4" OffsetHex = "00000030" Description = "TriggerSoarTime" DisplayMethod = "unsigned integer" / >
<Element Offset = "52" Vartype = "Float" Bytesize = "4" OffsetHex = "00000034" Description = "CameraLookInfluence" DisplayMethod = "unsigned integer" / >
<Element Offset = "56" Vartype = "Float" Bytesize = "4" OffsetHex = "00000038" Description = "ForwardInputMovementInfluence" DisplayMethod = "unsigned integer" / >
<Element Offset = "60" Vartype = "Float" Bytesize = "4" OffsetHex = "0000003C" Description = "BackwardInputMovementInfluence" DisplayMethod = "unsigned integer" / >
<Element Offset = "64" Vartype = "Float" Bytesize = "4" OffsetHex = "00000040" Description = "LeftRightInputMovementInfluence" DisplayMethod = "unsigned integer" / >
< / Elements>*/
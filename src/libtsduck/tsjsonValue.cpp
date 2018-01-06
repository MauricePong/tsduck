//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2018, Thierry Lelegard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------

#include "tsjsonValue.h"
TSDUCK_SOURCE;

// A general-purpose constant null JSON value.
const ts::json::Null ts::json::NullValue;


//----------------------------------------------------------------------------
// Default access to sub-component.
//----------------------------------------------------------------------------

const ts::json::Value& ts::json::Value::at(size_t index) const
{
    return NullValue;
}

const ts::json::Value& ts::json::Value::value(const UString& name) const
{
    return NullValue;
}


//----------------------------------------------------------------------------
// Conversion methods for strings.
//----------------------------------------------------------------------------

int64_t ts::json::String::toInteger(int64_t defaultValue) const
{
    int64_t i = 0;
    return _value.toInteger(i) ? i : defaultValue;
}

bool ts::json::String::toBoolean(bool defaultValue) const
{
    int i = 0;
    if (_value.similar(u"true") || _value.similar(u"yes") || _value.similar(u"on") || (_value.toInteger(i) && i != 0)) {
        return true;
    }
    else if (_value.similar(u"false") || _value.similar(u"no") || _value.similar(u"off") || (_value.toInteger(i) && i == 0)) {
        return false;
    }
    else {
        return defaultValue;
    }
}

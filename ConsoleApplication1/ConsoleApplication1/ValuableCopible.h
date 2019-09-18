#pragma once
#include "rapidjson-master/include/rapidjson/document.h"
#include "rapidjson-master/include/rapidjson/writer.h"
#include "rapidjson-master/include/rapidjson/stringbuffer.h"
#include "rapidjson-master/include/rapidjson/filereadstream.h"


using namespace rapidjson;

class ValueCopibable :public  Document
{

public:
	// Copy constructor 
	ValueCopibable()
	{
		
	}
	ValueCopibable& operator= (const ValueCopibable &p2)
	{
		Document::AllocatorType& allocator = this->GetAllocator();
		this->CopyFrom(p2, allocator);
		return *this;
	}
	ValueCopibable(Document &p2) {
		Document::AllocatorType& allocator = p2.GetAllocator();
		this->CopyFrom(p2, allocator);
	}
	ValueCopibable(Value &p2) {
		Document::AllocatorType& allocator = this->GetAllocator();
		this->CopyFrom(p2, allocator);
	}
	ValueCopibable(const ValueCopibable &p2) {
		Document::AllocatorType& allocator = this->GetAllocator();
		this->CopyFrom(p2, allocator);
	}
};



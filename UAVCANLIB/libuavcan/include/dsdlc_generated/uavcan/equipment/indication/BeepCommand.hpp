/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/apm/dronecan/libuavcan/dsdl/uavcan/equipment/indication/1080.BeepCommand.uavcan
 */

#ifndef UAVCAN_EQUIPMENT_INDICATION_BEEPCOMMAND_HPP_INCLUDED
#define UAVCAN_EQUIPMENT_INDICATION_BEEPCOMMAND_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

/******************************* Source text **********************************
#
# Nodes that are capable of producing sounds should obey.
#

float16 frequency  # Hz
float16 duration   # Sec
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.indication.BeepCommand
saturated float16 frequency
saturated float16 duration
******************************************************************************/

#undef frequency
#undef duration

namespace uavcan
{
namespace equipment
{
namespace indication
{

template <int _tmpl>
struct UAVCAN_EXPORT BeepCommand_
{
    typedef const BeepCommand_<_tmpl>& ParameterType;
    typedef BeepCommand_<_tmpl>& ReferenceType;

    struct ConstantTypes
    {
    };

    struct FieldTypes
    {
        typedef ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate > frequency;
        typedef ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate > duration;
    };

    enum
    {
        MinBitLen
            = FieldTypes::frequency::MinBitLen
            + FieldTypes::duration::MinBitLen
    };

    enum
    {
        MaxBitLen
            = FieldTypes::frequency::MaxBitLen
            + FieldTypes::duration::MaxBitLen
    };

    // Constants

    // Fields
    typename ::uavcan::StorageType< typename FieldTypes::frequency >::Type frequency;
    typename ::uavcan::StorageType< typename FieldTypes::duration >::Type duration;

    BeepCommand_()
        : frequency()
        , duration()
    {
        ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

#if UAVCAN_DEBUG
        /*
         * Cross-checking MaxBitLen provided by the DSDL compiler.
         * This check shall never be performed in user code because MaxBitLen value
         * actually depends on the nested types, thus it is not invariant.
         */
        ::uavcan::StaticAssert<32 == MaxBitLen>::check();
#endif
    }

    bool operator==(ParameterType rhs) const;
    bool operator!=(ParameterType rhs) const { return !operator==(rhs); }

    /**
     * This comparison is based on @ref uavcan::areClose(), which ensures proper comparison of
     * floating point fields at any depth.
     */
    bool isClose(ParameterType rhs) const;

    static int encode(ParameterType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    static int decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindMessage };
    enum { DefaultDataTypeID = 1080 };

    static const char* getDataTypeFullName()
    {
        return "uavcan.equipment.indication.BeepCommand";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

};

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool BeepCommand_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        frequency == rhs.frequency &&
        duration == rhs.duration;
}

template <int _tmpl>
bool BeepCommand_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(frequency, rhs.frequency) &&
        ::uavcan::areClose(duration, rhs.duration);
}

template <int _tmpl>
int BeepCommand_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::frequency::encode(self.frequency, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::duration::encode(self.duration, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int BeepCommand_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::frequency::decode(self.frequency, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::duration::decode(self.duration, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
template <int _tmpl>
::uavcan::DataTypeSignature BeepCommand_<_tmpl>::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0xBE9EA9FEC2B15D52ULL);

    FieldTypes::frequency::extendDataTypeSignature(signature);
    FieldTypes::duration::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

/*
 * Final typedef
 */
typedef BeepCommand_<0> BeepCommand;

namespace
{

const ::uavcan::DefaultDataTypeRegistrator< ::uavcan::equipment::indication::BeepCommand > _uavcan_gdtr_registrator_BeepCommand;

}

} // Namespace indication
} // Namespace equipment
} // Namespace uavcan

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::uavcan::equipment::indication::BeepCommand >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::uavcan::equipment::indication::BeepCommand::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::uavcan::equipment::indication::BeepCommand >::stream(Stream& s, ::uavcan::equipment::indication::BeepCommand::ParameterType obj, const int level)
{
    (void)s;
    (void)obj;
    (void)level;
    if (level > 0)
    {
        s << '\n';
        for (int pos = 0; pos < level; pos++)
        {
            s << "  ";
        }
    }
    s << "frequency: ";
    YamlStreamer< ::uavcan::equipment::indication::BeepCommand::FieldTypes::frequency >::stream(s, obj.frequency, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "duration: ";
    YamlStreamer< ::uavcan::equipment::indication::BeepCommand::FieldTypes::duration >::stream(s, obj.duration, level + 1);
}

}

namespace uavcan
{
namespace equipment
{
namespace indication
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::uavcan::equipment::indication::BeepCommand::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::uavcan::equipment::indication::BeepCommand >::stream(s, obj, 0);
    return s;
}

} // Namespace indication
} // Namespace equipment
} // Namespace uavcan

#endif // UAVCAN_EQUIPMENT_INDICATION_BEEPCOMMAND_HPP_INCLUDED
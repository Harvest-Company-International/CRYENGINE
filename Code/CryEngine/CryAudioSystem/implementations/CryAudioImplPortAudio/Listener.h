// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <IListener.h>

namespace CryAudio
{
namespace Impl
{
namespace PortAudio
{
class CListener final : public IListener
{
public:

	CListener() = delete;
	CListener(CListener const&) = delete;
	CListener(CListener&&) = delete;
	CListener& operator=(CListener const&) = delete;
	CListener& operator=(CListener&&) = delete;

	explicit CListener(CTransformation const& transformation)
		: m_transformation(transformation)
	{}

	virtual ~CListener() override = default;

	// CryAudio::Impl::IListener
	virtual void                   Update(float const deltaTime) override                            {}
	virtual void                   SetName(char const* const szName) override;
	virtual void                   SetTransformation(CTransformation const& transformation) override { m_transformation = transformation; }
	virtual CTransformation const& GetTransformation() const override                                { return m_transformation; }
	// ~CryAudio::Impl::IListener

#if defined(INCLUDE_PORTAUDIO_IMPL_PRODUCTION_CODE)
	char const* GetName() const { return m_name.c_str(); }
#endif  // INCLUDE_PORTAUDIO_IMPL_PRODUCTION_CODE

private:

	CTransformation m_transformation;

#if defined(INCLUDE_PORTAUDIO_IMPL_PRODUCTION_CODE)
	CryFixedStringT<MaxObjectNameLength> m_name;
#endif  // INCLUDE_PORTAUDIO_IMPL_PRODUCTION_CODE
};
} // namespace PortAudio
} // namespace Impl
} // namespace CryAudio
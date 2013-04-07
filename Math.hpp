#ifndef INCLUDED_GAMEENGINE_MATH_HPP
#define INCLUDED_GAMEENGINE_MATH_HPP

#include <cmath>

namespace GameEngine
{
	typedef int		ScriptGU;
	const int SCRIPT_GU_DECIMAL_SHIFT	= 10;

	inline ScriptGU MakeGU( int i, int d )
	{
		return i << SCRIPT_GU_DECIMAL_SHIFT + d;
	}

	inline ScriptGU GUAdd( const ScriptGU& lhs, const ScriptGU& rhs )
	{
		return lhs + rhs;
	}

	inline ScriptGU GUSub( const ScriptGU& lhs, const ScriptGU& rhs )
	{
		return lhs - rhs;
	}

	inline ScriptGU GUMul( const ScriptGU& lhs, const ScriptGU& rhs )
	{
		long long value = ( static_cast < long long > ( lhs ) * rhs );
		return value >> SCRIPT_GU_DECIMAL_SHIFT;
	}

	inline ScriptGU GUDiv( const ScriptGU& lhs, const ScriptGU& rhs )
	{
		ScriptGU value = ( static_cast < long long > ( lhs << SCRIPT_GU_DECIMAL_SHIFT ) / rhs );
		return value;
	}

	inline ScriptGU GUNeg( const ScriptGU& gu )
	{
		return -gu;
	}

	inline ScriptGU GUEq( const ScriptGU& lhs, const ScriptGU& rhs )
	{
		return lhs == rhs;
	}

	inline ScriptGU GUNe( const ScriptGU& lhs, const ScriptGU& rhs )
	{
		return lhs != rhs;
	}

	inline ScriptGU GUGt( const ScriptGU& lhs, const ScriptGU& rhs )
	{
		return lhs > rhs;
	}

	inline ScriptGU GUGe( const ScriptGU& lhs, const ScriptGU& rhs )
	{
		return lhs >= rhs;
	}

	inline ScriptGU GULt( const ScriptGU& lhs, const ScriptGU& rhs )
	{
		return lhs < rhs;
	}

	inline ScriptGU GULe( const ScriptGU& lhs, const ScriptGU& rhs )
	{
		return lhs <= rhs;
	}



	/*struct ScriptGU
	{
		int		m_Value;

	};*/
	
	/*
	class GameUnit
	{
	private:
		enum
		{
			UNIT		= 1000,
		};
		int			m_Value;
	public:
		GameUnit();
		GameUnit( int i );
		GameUnit( int u, int l );
		GameUnit( float f );
		GameUnit( const GameUnit& u );
		~GameUnit();
		GameUnit& operator=( const GameUnit& u );
		GameUnit operator+( const GameUnit& u );
		GameUnit operator-( const GameUnit& u );
		GameUnit operator*( const GameUnit& u );
		GameUnit operator/( const GameUnit& u );
		GameUnit operator>>( int shift );
		GameUnit operator<<( int shift );
		GameUnit& operator+=( const GameUnit& u );
		GameUnit& operator-=( const GameUnit& u );
		GameUnit& operator*=( const GameUnit& u );
		GameUnit& operator/=( const GameUnit& u );
		GameUnit& operator>>=( int shift );
		GameUnit& operator<<=( int shift );
		bool operator<( const GameUnit& u );
		bool operator>( const GameUnit& u );
		bool operator<=( const GameUnit& u );
		bool operator>=( const GameUnit& u );
		bool operator==( const GameUnit& u );
		bool operator!=( const GameUnit& u );

		int GetRawValue() const;
		int GetUnit() const;
		int GetInt() const;
		float GetFloat() const;
	};

	inline GameUnit::GameUnit() : m_Value( 0 )
	{
	}

	inline GameUnit::GameUnit( int i ) : m_Value( i * UNIT )
	{
	}

	inline GameUnit::GameUnit( int u, int l ) : m_Value( u * UNIT + l )
	{
	}

	inline GameUnit::GameUnit( float f )
	{
		m_Value = static_cast < int > ( f * UNIT );
	}

	inline GameUnit::GameUnit( const GameUnit& u )
	{
		m_Value = u.m_Value;
	}

	inline GameUnit::~GameUnit()
	{
		m_Value = 0;
	}

	inline GameUnit& GameUnit::operator=( const GameUnit& u )
	{
		m_Value = u.m_Value;
		return *this;
	}

	inline GameUnit GameUnit::operator+( const GameUnit& u )
	{
		GameUnit tmp( *this );
		tmp += u;
		return tmp;
	}

	inline GameUnit GameUnit::operator-( const GameUnit& u )
	{
		GameUnit tmp( *this );
		tmp -= u;
		return tmp;
	}

	inline GameUnit GameUnit::operator*( const GameUnit& u )
	{
		GameUnit tmp( *this );
		tmp *= u;
		return tmp;
	}

	inline GameUnit GameUnit::operator/( const GameUnit& u )
	{
		GameUnit tmp( *this );
		tmp /= u;
		return tmp;
	}

	inline GameUnit GameUnit::operator>>( int shift )
	{
		GameUnit tmp( *this );
		tmp >>= shift;
		return tmp;
	}

	inline GameUnit GameUnit::operator<<( int shift )
	{
		GameUnit tmp( *this );
		tmp <<= shift;
		return tmp;
	}

		
	inline GameUnit& GameUnit::operator+=( const GameUnit& u )
	{
		m_Value += u.m_Value;
		return *this;
	}

	inline GameUnit& GameUnit::operator-=( const GameUnit& u )
	{
		m_Value -= u.m_Value;
		return *this;
	}

	inline GameUnit& GameUnit::operator*=( const GameUnit& u )
	{
		m_Value = ( static_cast < long long > ( m_Value ) * u.m_Value ) / UNIT;
		return *this;
	}

	inline GameUnit& GameUnit::operator/=( const GameUnit& u )
	{
		m_Value = ( static_cast < long long > ( m_Value * UNIT ) / u.m_Value );
		return *this;
	}

	inline GameUnit& GameUnit::operator>>=( int shift )
	{
		m_Value >>= shift;
		return *this;
	}

	inline GameUnit& GameUnit::operator<<=( int shift )
	{
		m_Value <<= shift;
		return *this;
	}


	inline bool GameUnit::operator<( const GameUnit& u )
	{
		return m_Value < u.m_Value;
	}

	inline bool GameUnit::operator>( const GameUnit& u )
	{
		return m_Value > u.m_Value;
	}

	inline bool GameUnit::operator<=( const GameUnit& u )
	{
		return m_Value <= u.m_Value;
	}

	inline bool GameUnit::operator>=( const GameUnit& u )
	{
		return m_Value >= u.m_Value;
	}

	inline bool GameUnit::operator==( const GameUnit& u )
	{
		return m_Value == u.m_Value;
	}

	inline bool GameUnit::operator!=( const GameUnit& u )
	{
		return m_Value != u.m_Value;
	}

	inline int GameUnit::GetRawValue() const
	{
		return m_Value;
	}

	inline int GameUnit::GetUnit() const
	{
		return UNIT;
	}

	inline int GameUnit::GetInt() const
	{
		return m_Value / UNIT;
	}

	inline float GameUnit::GetFloat() const
	{
		return m_Value * 1.0f / UNIT;
	}
	*/
	



/*
	class GameUnit
	{
	public:
		enum
		{
			SHIFT		= SCRIPT_GU_DECIMAL_SHIFT,
		};
	private:
		union Test
		{
			struct Bits
			{
				unsigned	m_Decimal : 10;
				signed		m_Integer : 22;
			};
			struct Sign
			{
				unsigned	m_Value : 31;
				unsigned	m_Sign : 1;
			};
			int			m_Value;
			Bits		m_Bits;
			Sign		m_Sign;
		};
	public:
		GameUnit();
		GameUnit( int i );
		GameUnit( int u, int l );
		GameUnit( float f );
		GameUnit( const GameUnit& u );
		~GameUnit();
		GameUnit& operator=( const GameUnit& u );
		GameUnit operator+( const GameUnit& u );
		GameUnit operator-( const GameUnit& u );
		GameUnit operator*( const GameUnit& u );
		GameUnit operator/( const GameUnit& u );
		GameUnit operator>>( int shift );
		GameUnit operator<<( int shift );
		GameUnit& operator+=( const GameUnit& u );
		GameUnit& operator-=( const GameUnit& u );
		GameUnit& operator*=( const GameUnit& u );
		GameUnit& operator/=( const GameUnit& u );
		GameUnit& operator>>=( int shift );
		GameUnit& operator<<=( int shift );
		bool operator<( const GameUnit& u );
		bool operator>( const GameUnit& u );
		bool operator<=( const GameUnit& u );
		bool operator>=( const GameUnit& u );
		bool operator==( const GameUnit& u );
		bool operator!=( const GameUnit& u );

		int GetRawValue() const;
		int GetUnit() const;
		int GetInt() const;
		float GetFloat() const;
		int GetIntegerPart() const;
		int GetDecimalPart() const;
	};

	inline GameUnit::GameUnit() : m_Value( 0 )
	{
	}

	inline GameUnit::GameUnit( int i )
	{
		m_Value = i << SHIFT;
	}

	inline GameUnit::GameUnit( int u, int l ) : m_Value( u > 0 ? ( u << SHIFT ) + l : - ( (-u) << SHIFT ) + l )
	{
	}

	inline GameUnit::GameUnit( float f )
	{
		m_Value = static_cast < int > ( f * ( 1 << SHIFT ) );
	}

	inline GameUnit::GameUnit( const GameUnit& u )
	{
		m_Value = u.m_Value;
	}

	inline GameUnit::~GameUnit()
	{
		m_Value = 0;
	}

	inline GameUnit& GameUnit::operator=( const GameUnit& u )
	{
		m_Value = u.m_Value;
		return *this;
	}

	inline GameUnit GameUnit::operator+( const GameUnit& u )
	{
		GameUnit tmp( *this );
		tmp += u;
		return tmp;
	}

	inline GameUnit GameUnit::operator-( const GameUnit& u )
	{
		GameUnit tmp( *this );
		tmp -= u;
		return tmp;
	}

	inline GameUnit GameUnit::operator*( const GameUnit& u )
	{
		GameUnit tmp( *this );
		tmp *= u;
		return tmp;
	}

	inline GameUnit GameUnit::operator/( const GameUnit& u )
	{
		GameUnit tmp( *this );
		tmp /= u;
		return tmp;
	}

	inline GameUnit GameUnit::operator>>( int shift )
	{
		GameUnit tmp( *this );
		tmp >>= shift;
		return tmp;
	}

	inline GameUnit GameUnit::operator<<( int shift )
	{
		GameUnit tmp( *this );
		tmp <<= shift;
		return tmp;
	}

		
	inline GameUnit& GameUnit::operator+=( const GameUnit& u )
	{
		m_Value += u.m_Value;
		return *this;
	}

	inline GameUnit& GameUnit::operator-=( const GameUnit& u )
	{
		m_Value -= u.m_Value;
		return *this;
	}

	inline GameUnit& GameUnit::operator*=( const GameUnit& u )
	{
		int sign = m_Sign.m_Sign ^ u.m_Sign.m_Sign;
		if( sign == 1 ){
			int a = 0;
		}
		long long value = ( static_cast < long long > ( m_Value ) * u.m_Value );
		//m_Value = ( ( value >> SHIFT ) ^ ( ( 1 - sign ) - 1 ) ) + sign;
		m_Value = value >> SHIFT;
		
		
		//m_Sign.m_Value = ( static_cast < long long > ( m_Sign.m_Value ) * u.m_Sign.m_Value );
		//long long value = ( static_cast < long long > ( m_Value ) * u.m_Value );
		//m_Value = value > 0 ? ( value >> SHIFT ) : -( (-value) >> SHIFT );
		return *this;
	}

	inline GameUnit& GameUnit::operator/=( const GameUnit& u )
	{
		//int sign = m_Sign.m_Sign;
		int value = ( static_cast < long long > ( m_Value << SHIFT ) / u.m_Value );
		//m_Value = ( ( value ) ^ ( ( 1 - sign ) ) ) + sign;
		m_Value = value;
		return *this;
	}

	inline GameUnit& GameUnit::operator>>=( int shift )
	{
		m_Value >>= shift;
		return *this;
	}

	inline GameUnit& GameUnit::operator<<=( int shift )
	{
		m_Value <<= shift;
		return *this;
	}


	inline bool GameUnit::operator<( const GameUnit& u )
	{
		return m_Value < u.m_Value;
	}

	inline bool GameUnit::operator>( const GameUnit& u )
	{
		return m_Value > u.m_Value;
	}

	inline bool GameUnit::operator<=( const GameUnit& u )
	{
		return m_Value <= u.m_Value;
	}

	inline bool GameUnit::operator>=( const GameUnit& u )
	{
		return m_Value >= u.m_Value;
	}

	inline bool GameUnit::operator==( const GameUnit& u )
	{
		return m_Value == u.m_Value;
	}

	inline bool GameUnit::operator!=( const GameUnit& u )
	{
		return m_Value != u.m_Value;
	}

	inline int GameUnit::GetRawValue() const
	{
		return m_Value;
	}

	inline int GameUnit::GetUnit() const
	{
		return 1 << SHIFT;
	}

	inline int GameUnit::GetInt() const
	{

		return m_Bits.m_Integer;
		//return m_Value > 0 ? m_Value >> SHIFT : -( (-m_Value) >> SHIFT );
	}

	inline float GameUnit::GetFloat() const
	{
		//return m_Bits.m_Integer * 1.0f;
		return m_Value > 0 ? m_Value * 1.0f / ( 1 << SHIFT ) : -( (-m_Value) * 1.0f / ( 1 << SHIFT ) );
	}

	inline int GameUnit::GetIntegerPart() const
	{
		return m_Bits.m_Integer;
	}

	inline int GameUnit::GetDecimalPart() const
	{
		return m_Bits.m_Decimal;
	}



	// int -> GameUnit
	GameUnit IntToGU( int val );

	// float -> GameUnit (¬”“_ˆÈ‰º3Œ…‚Ü‚Å•Û‘¶)
	GameUnit FloatToGU( float val );

	// GameUnit -> int
	int GUToInt( GameUnit val );

	// sin
	GameUnit SinGU( GameUnit deg );

	// cos
	GameUnit CosGU( GameUnit deg );

	// tan
	GameUnit TanGU( GameUnit deg );

	// atan2
	GameUnit Atan2GU( GameUnit y, GameUnit x );

	// abs
	GameUnit AbsGU( GameUnit val );
*/
}

#endif

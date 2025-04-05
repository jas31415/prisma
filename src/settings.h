class Settings final
{
public:
	explicit Settings() = default;
	Settings(const Settings& other) = default;
	Settings& operator=(const Settings& other) = default;
	Settings(Settings&& other) = default;
	Settings& operator=(Settings&& other) = default;
	~Settings() = default;

	int GetFPS(bool getTarget) const;
	bool IsVSyncEnabled() const;
	void SetVSync(bool newTruth);

private:
	const int c_TargetFPS;
	bool m_DoVSync;
};
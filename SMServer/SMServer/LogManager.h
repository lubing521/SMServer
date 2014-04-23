#pragma once

namespace SM
{
	struct LogData
	{
		int m_id;
		char* m_write_data;
	};


	// id�� ������ ostream�� ���� ���
	const static int LOG_DEFAULT = 0;
	// Log�� ���� ���� �׻� LogManager�� ���� ����.
	class LogManager
	{
	private:
		static LogManager* m_instance;
	public:
		static LogManager* GetInstance();
		static void Release();
	private:
		LogManager();
		~LogManager();

	public:
		// �α� ���� ������ �����ϰ� ����д�.
		bool RegisterFile(const int p_id, const char* p_filepath);

	public:
		// �α׸� �ֿܼ� �ٷ� ����Ѵ�.
		void Logging(const char* p_string, ...);
		// �α׸� ť�� ����Ѵ�.
		void Logging(const int p_id, const char* p_string, ...);

	private:
		// ��ϵ� ť�� �̾Ƽ� ����Ѵ�.
		static unsigned int WINAPI LoggingThreadFunction(LPVOID p_param);
		static void CALLBACK LoggingAPCFunction(ULONG_PTR p_param);

	private:
		DWORD m_thread_id;
		HANDLE m_thread_handle;
	private:
		map<int, FILE*> m_handle_map;
	};
}
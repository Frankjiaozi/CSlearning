from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

def auto_login(username, password, login_url):
    """
    自动登录脚本
    :param username: 用户名
    :param password: 密码
    :param login_url: 登录页面URL
    """
    # 1. 配置浏览器选项
    options = webdriver.ChromeOptions()
    options.add_argument('--no-sandbox')
    options.add_argument('--disable-dev-shm-usage')
    # options.add_argument('--headless')  # 无头模式（不显示浏览器窗口）
    
    # 2. 启动浏览器
    driver = webdriver.Chrome(options=options)
    
    try:
        # 3. 打开登录页面
        driver.get(login_url)
        print(f"正在访问: {login_url}")
        
        # 4. 等待并查找用户名输入框
        # 需要根据实际网站修改选择器
        wait = WebDriverWait(driver, 10)
        username_field = wait.until(
            EC.presence_of_element_located((By.ID, "username"))  # 或者 By.NAME, By.CSS_SELECTOR
        )
        
        # 5. 查找密码输入框
        password_field = driver.find_element(By.ID, "password")
        
        # 6. 查找登录按钮
        login_button = driver.find_element(By.ID, "login-button")
        
        # 7. 输入凭证
        username_field.clear()
        username_field.send_keys(username)
        time.sleep(1)  # 模拟人工输入延迟
        
        password_field.clear()
        password_field.send_keys(password)
        time.sleep(1)
        
        # 8. 点击登录
        login_button.click()
        print("正在提交登录信息...")
        
        # 9. 等待登录成功（根据成功后的页面元素判断）
        wait.until(EC.url_contains("dashboard"))  # 或等待特定元素出现
        print("登录成功！")
        
        # 10. 保存cookies（可选）
        cookies = driver.get_cookies()
        print(f"获取到 {len(cookies)} 个cookies")
        
        return driver, cookies
        
    except Exception as e:
        print(f"登录失败: {str(e)}")
        driver.save_screenshot("login_error.png")  # 截图调试
        return driver, None

# 使用示例
if __name__ == "__main__":
    # 需要根据实际情况修改这些参数
    LOGIN_URL = "https://example.com/login"
    USERNAME = "your_username"
    PASSWORD = "your_password"
    
    driver, cookies = auto_login(USERNAME, PASSWORD, LOGIN_URL)
    
    # 继续操作...
    # driver.get("https://example.com/dashboard")
    
    # 最后关闭浏览器
    # driver.quit()
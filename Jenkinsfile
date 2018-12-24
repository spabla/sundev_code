pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh 'echo "Building Utilities"'
                sh '''
                    cd ./e_bear_morse_code_project_master/blue_bear_code_challenge/utilities/Debug
		    make clean
		    make
                '''
            }
        }
    }
}

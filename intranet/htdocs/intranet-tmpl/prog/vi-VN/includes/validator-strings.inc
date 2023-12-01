<!-- validator-strings.inc -->
<script>
    $(document).ready(function(){
        jQuery.extend(jQuery.validator.messages, {
            required: _("Trường này bắt buộc."),
            remote: _("Hãy sửa trường này."),
            email: _("Hãy nhập đúng địa chỉ thư điện tử."),
            url: _("Hãy nhập đúng giá trị URL."),
            date: _("Hãy nhập đúng giá trị ngày."),
            dateISO: _("Hãy nhập đúng giá trị ngày (ISO)."),
            number: _("Hãy nhập đúng con số."),
            digits: _("Chỉ nhập một kí tự số."),
            equalTo: _("Hãy nhập lại cùng giá trị."),
            number: _("Please add amount in valid format: 0.00"),
            maxlength: $.validator.format(_("Hãy nhập nhiều hơn {0} kí tự.")),
            minlength: $.validator.format(_("Hãy nhập ít nhất {0} kí tự.")),
            rangelength: $.validator.format(_("Hãy nhập giá trị độ dài trong khoảng {0} và {1} .")),
            range: $.validator.format(_("Hãy nhập giá trị giữa {0} và {1}.")),
            max: $.validator.format(_("Hãy nhập giá trị nhỏ hơn hoặc bằng {0}.")),
            min: $.validator.format(_("Hãy nhập giá trị lớn hơn hoặc bằng {0}.")),
            phone: $.validator.format(_("Please enter a valid phone number."))
        });
    });
</script>
<!-- / validator-strings.inc -->

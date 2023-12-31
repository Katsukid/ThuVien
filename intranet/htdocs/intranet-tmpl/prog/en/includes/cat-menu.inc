[% USE Koha %]
<div id="navmenu">
    <div id="navmenulist">

        [% IF ( CAN_user_tools_stage_marc_import || CAN_user_tools_manage_staged_marc ) %]
        <h5>Import</h5>
        <ul>
            [% IF ( CAN_user_tools_stage_marc_import ) %]
            <li>
                <a href="/cgi-bin/koha/tools/stage-marc-import.pl">Kiểm duyệt các bản ghi nhập theo lô</a>
            </li>
            [% END %]
            [% IF ( CAN_user_tools_manage_staged_marc ) %]
            <li>
                <a href="/cgi-bin/koha/tools/manage-marc-import.pl">Manage staged records</a>
            </li>
            [% END %]
        </ul>
        [% END %]

        [% IF ( CAN_user_tools_export_catalog ) %]
        <h5>Export</h5>
        <ul>
            [% IF ( CAN_user_tools_export_catalog ) %]
            <li>
                <a href="/cgi-bin/koha/tools/export.pl">Xuất dữ liệu</a>
            </li>
            [% END %]
        </ul>
        [% END %]

        [% IF ( CAN_user_tools_inventory || ( ( Koha.Preference('OpacCatalogConcerns') || Koha.Preference('CatalogConcerns') ) && CAN_user_editcatalogue_edit_catalogue ) ) %]
        <h5>Reports</h5>
        <ul>
            [% IF ( CAN_user_tools_inventory ) %]
            <li>
                <a href="/cgi-bin/koha/tools/inventory.pl">Inventory</a>
            </li>
            [% END %]
            [% IF ( Koha.Preference('OpacCatalogConcerns') || Koha.Preference('CatalogConcerns') ) && CAN_user_editcatalogue_edit_catalogue %]
            <li>
                <a href="/cgi-bin/koha/cataloguing/concerns.pl">Catalog concerns</a>
            </li>
            [% END %]
        </ul>
        [% END %]

        [% IF ( CAN_user_tools_items_batchmod || CAN_user_tools_items_batchdel || CAN_user_tools_records_batchmod || CAN_user_tools_records_batchdel || CAN_user_tools_marc_modification_templates ) %]
        <h5>Thao tác theo lô</h5>
        <ul>
            [% IF ( CAN_user_tools_items_batchmod ) %]
            <li>
                <a href="/cgi-bin/koha/tools/batchMod.pl">Batch item modification</a>
            </li>
            [% END %]
            [% IF ( CAN_user_tools_items_batchdel ) %]
            <li>
                <a href="/cgi-bin/koha/tools/batchMod.pl?del=1">Batch item deletion</a>
            </li>
            [% END %]
            [% IF CAN_user_tools_records_batchmod %]
            <li>
                <a href="/cgi-bin/koha/tools/batch_record_modification.pl"> Sửa đổi bản ghi hàng loạt</a>
            </li>
            [% END %]
            [% IF CAN_user_tools_records_batchdel %]
            <li>
                <a href="/cgi-bin/koha/tools/batch_delete_records.pl"> Xóa bản ghi hàng loạt</a>
            </li>
            [% END %]
            [% IF ( CAN_user_tools_marc_modification_templates ) %]
            <li>
                <a href="/cgi-bin/koha/tools/marc_modification_templates.pl">MARC modification templates</a>
            </li>
            [% END %]
        </ul>
        [% END %]

        [% IF ( CAN_user_tools_items_batchmod || ( CAN_user_stockrotation_manage_rotas && Koha.Preference('StockRotation') ) ) %]
        <h5>Tự động hóa</h5>
        <ul>
            [% IF ( CAN_user_tools_items_batchmod ) %]
            <li>
                <a href="/cgi-bin/koha/tools/automatic_item_modification_by_age.pl">Tự động chỉnh sửa tài liệu theo tuổi</a>
            </li>
            [% END %]
            [% IF ( CAN_user_stockrotation_manage_rotas && Koha.Preference('StockRotation') ) %]
            <li>
                <a href="/cgi-bin/koha/tools/stockrotation.pl">Stock rotation</a>
            </li>
            [% END %]
        </ul>
        [% END %]

        [% IF ( CAN_user_tools_label_creator || CAN_user_tools_upload_local_cover_images ) %]
        <h5>Tools</h5>
        <ul>
            [% IF ( CAN_user_tools_label_creator ) %]
            <li>
                <a href="/cgi-bin/koha/labels/label-home.pl">Label creator</a>
            </li>
            <li>
                <a href="/cgi-bin/koha/labels/barcode-print.pl"> Trình tạo hình ảnh mã vạch</a>
            </li>
            <li>
                <a href="/cgi-bin/koha/labels/spinelabel-home.pl">Quick spine label creator</a>
            </li>
            [% END %]

            [% IF ( CAN_user_tools_upload_local_cover_images ) %]
            <li>
                <a href="/cgi-bin/koha/tools/upload-cover-image.pl">Upload local cover image</a>
            </li>
            [% END %]
        </ul>
        [% END %]

    </div>
</div>
